#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  std::cout << cv::getVersionString() << std::endl;
  cv::Mat image0 = cv::imread("barbara.ppm", cv::IMREAD_COLOR_BGR);

  const int w = image0.cols;  // 704
  const int h = image0.rows;  // 480
  const int nc = image0.channels();

  const int XR = 16;
  const int YR = 16;

  /****************************** Encoder ******************************/
  // 色空間変換: RGB -> YCbCr
  cv::cvtColor(image0, image0, cv::COLOR_BGR2YCrCb);

  std::vector<cv::Mat> ycrcb;
  cv::split(image0, ycrcb);  // Y, Cr, Cbをそれぞれ独立したMatに分割

  // 色間引き (Color subsampling): 444 -> 420
  cv::resize(ycrcb[1], ycrcb[1], cv::Size(), 1.0 / XR, 1.0 / YR, cv::INTER_LINEAR);
  cv::resize(ycrcb[2], ycrcb[2], cv::Size(), 1.0 / XR, 1.0 / YR, cv::INTER_LINEAR);

  /****************************** Decoder ******************************/
  // 色差成分を補間: 420 -> 444
  cv::resize(ycrcb[1], ycrcb[1], cv::Size(), XR, YR, cv::INTER_LINEAR);
  cv::resize(ycrcb[2], ycrcb[2], cv::Size(), XR, YR, cv::INTER_LINEAR);
  cv::merge(ycrcb, image0);  // Y, Cr, CbをひとつのMatに統合

  // 色空間変換: YCbcr -> RGB
  cv::cvtColor(image0, image0, cv::COLOR_YCrCb2BGR);

  cv::imshow("Reconstructed", image0);

  cv::waitKey(0);

  return 0;
}