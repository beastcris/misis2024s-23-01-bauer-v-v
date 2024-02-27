#include <opencv2/opencv.hpp>
#include <iostream>


int main() {
  
  cv::Mat img = cv::imread("C:/Users/Huawei/Desktop/2task.png");


  if (img.empty()) {
    std::cout << "Failed";
    std::cin.get();
    return -1;
  }
  cv::Mat OldImg = cv::imread("C:/Users/Huawei/Desktop/2task.png");

  img.convertTo(img, -1, 4, 0);

  cv::String first = "first window";
  cv::String second = "second window";
  cv::namedWindow(first);
  cv::namedWindow(second);

  cv::imshow(first, OldImg);
  cv::imshow(second, img);

  cv::waitKey(0);

  cv::destroyAllWindows();
}