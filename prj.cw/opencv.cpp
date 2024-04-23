#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

const double PI = acos(-1.0);


double round_num(double num, int decimal) {
  const double multip = std::pow(10.0, decimal);
  return (std::round(num * multip) / multip);
}

double** GaussianMatrix(const int& length,  const double& sigma ) {
  double** matrix = new double* [length];

  for (size_t i = 0; i < length; ++i) {
    double* row = new double[length];
    matrix[i] = row;
  }

  for (size_t i = 0; i < length; ++i) {
    for (size_t j = 0; j < length; ++j) {
      matrix[i][j] = std::exp(-(std::abs(length/2-static_cast<int>(i)) * std::abs(length / 2 - static_cast<int>(i)) + std::abs(length / 2 - static_cast<int>(j)) * std::abs(length / 2 - static_cast<int>(j))) / (2 * sigma * sigma))/(2*PI*sigma*sigma);
      matrix[i][j] = round_num(matrix[i][j], 5);
    }
  }

  return matrix;
}


int main() {
  //std::cout << std::fixed << std::setprecision(5);

  double sigma = 1.5;
  int matrix_lenght = 1 + 2 * ceil(2 * sigma);
  double** weights = GaussianMatrix(matrix_lenght, sigma);


  cv::Mat img = cv::imread("C:/Users/Huawei/Desktop/noise_mona2.jpg");
  cv::Mat img_new = cv::imread("C:/Users/Huawei/Desktop/noise_mona2.jpg");
  cv::Mat test = img.clone();

  for (size_t i = 0; i < img.rows; ++i) {
    for (size_t j = 0; j < img.cols; ++j) {
      
      uchar b_sum = 0;
      uchar g_sum = 0;
      uchar r_sum = 0;
      for (size_t i_ = std::max( static_cast<int>(i) - matrix_lenght / 2, 0); i_ <= std::min( static_cast<int>(i) + matrix_lenght/2, img.rows - 1); ++i_) {
        for (size_t j_ = std::max(static_cast<int>(j) - matrix_lenght / 2, 0); j_ <= std::min(static_cast<int>(j) + matrix_lenght/2, img.cols - 1); ++j_) {
          cv::Vec3b& BGR = img.at<cv::Vec3b>(i_, j_);
          b_sum += BGR[0] * weights[matrix_lenght / 2 - std::abs(static_cast<int>(i_) - std::abs(static_cast<int>(i)))][matrix_lenght / 2 - std::abs(static_cast<int>(j_) - std::abs(static_cast<int>(j)))];
          g_sum += BGR[1] * weights[matrix_lenght / 2 - std::abs(static_cast<int>(i_) - std::abs(static_cast<int>(i)))][matrix_lenght / 2 - std::abs(static_cast<int>(j_) - std::abs(static_cast<int>(j)))];
          r_sum += BGR[2] * weights[matrix_lenght / 2 - std::abs(static_cast<int>(i_) - std::abs(static_cast<int>(i)))][matrix_lenght / 2 - std::abs(static_cast<int>(j_) - std::abs(static_cast<int>(j)))];
        }
      }
      cv::Vec3b& pix = img_new.at<cv::Vec3b>(i, j);
      pix[0] = b_sum;
      pix[1] = g_sum;
      pix[2] = r_sum;

    }
    std::cout << '\n';
  }

  cv::GaussianBlur(test, test, cv::Size(13, 13), 0);

  cv::String window_name1 = "old_img";
  cv::String window_name2 = "new_img";

  cv::namedWindow(window_name1);
  cv::namedWindow(window_name2);

  cv::imshow(window_name1, img);
  cv::imshow(window_name2, img_new);
  cv::waitKey(0);
  cv::waitKey(0);
}