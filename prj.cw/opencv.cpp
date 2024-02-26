#include <opencv2/opencv.hpp>
#include <iostream>


int main() {
  
  cv::VideoCapture cap("C:/Users/Huawei/source/repos/opencv/sources/samples/cpp/tutorial_code/calib3d/real_time_pose_estimation/Data/box.mp4");

  if (cap.isOpened() == false)
  {
    std::cout << "Cannot open the video file" << std::endl;
    std::cin.get(); 
    return -1;
  }

  
  cv::String wn = "My first vidoe";
  cv::namedWindow(wn, cv::WINDOW_NORMAL);

  bool bSuccess = true;
  while (bSuccess!=false) {
    cv::Mat frame;
    bool bSuccess = cap.read(frame);

    cv::imshow(wn, frame);


    if (cv::waitKey(10) == 27)
    {
      std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
      break;
    }
  }
}