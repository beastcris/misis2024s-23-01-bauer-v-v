add_executable(opencv opencv.cpp)

find_package(OpenCV CONFIG REQUIRED)
target_link_libraries(opencv 
  PRIVATE opencv_core
          opencv_imgproc
          opencv_highgui
)

