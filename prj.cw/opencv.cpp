#include <opencv2/opencv.hpp>
#include <iostream>


int main() {
  
  cv::Mat img = cv::imread("C:/Users/Huawei/Desktop/data2.png");


  if (img.empty()) {
    std::cout << "Failed";
    std::cin.get();
    return -1;
  }
  
  cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

  cv::Mat new_img;
  cv::equalizeHist(img, new_img);

  cv::String windowNameOldPic = "Old Img";
  cv::String windowNameNewPic = "New Img";

  cv::namedWindow(windowNameNewPic);
  cv::namedWindow(windowNameOldPic);

  cv::imshow(windowNameOldPic, img);
  cv::imshow(windowNameNewPic, new_img);

  cv::waitKey(0);

  cv::destroyAllWindows();

}