#include <semcv/semcv.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv2/core/utility.hpp>

float srgb2linrgb_naive_u2f(const uint8_t v) {
  float inp = v / 255.0f;
  float out = 0.0f;
  if (inp <= 0.04045f) {
    out = inp / 12.92f;
  } else {
    out = std::pow(((inp + 0.055f) / 1.055), 2.4f);
  }
  return out;
}

//double srgb2linrgb_naive_u2d(const uint8_t v) {
//}

const uint8_t linrgb2srb_naive(const float inp) {
  float out = 0.0f;
  if (inp <= 0.0031308f) {
    out = 12.92f * inp;
  } else {
    out = 1.055*std::pow(inp, 1.0f/2.4f) - 0.055;
  }
  return out;
}

void rgb_s2l(const cv::Mat1b& inp, cv::Mat1f& out) {
  if (0 == out.data || out.cols != inp.cols || out.rows != inp.rows) {
    out = cv::Mat1f(inp.rows, inp.cols);
  }
  for (int i_row = 0; i_row < inp.rows; i_row += 1) {
    for (int i_col = 0; i_col < inp.cols; i_col += 1) {
      out.at<float>(i_row, i_col) = srgb2linrgb_naive_u2f(inp.at<uint8_t>(i_row, i_col));
    }
  }
}

void rgb_s2l(const cv::Mat3b& inp, cv::Mat3f& out) {
  if (0 == out.data || out.cols != inp.cols || out.rows != inp.rows) {
    out = cv::Mat3f(inp.rows, inp.cols);
  }
  cv::Mat1b imb_inp = inp.reshape(1, inp.rows);
  cv::Mat1f imf_out = out.reshape(1, out.rows);
  rgb_s2l(imb_inp, imf_out);
}

void gen_and_print() {
  for (int i = 0; i < 256; i += 1) {
    float f = srgb2linrgb_naive_u2f(static_cast<uint8_t>(i));
    //std::cout << f << ",\n";
    std::cout << std::format("{},\n", f);
  }
}

int main(int argc, char* argv[]) {
  gen_and_print();
  //if (1 == argc) {
  //  std::cout << "Use key -h to get help.";
  //  return 0;
  //}
  cv::Mat1b imb_line1(1, 256);
  for (int i_col = 0; i_col < imb_line1.cols; i_col += 1) {
    imb_line1.at<uint8_t>(0, i_col) = static_cast<uint8_t>(i_col);
  }
  cv::imwrite("rbg_line.png", imb_line1);
  cv::Mat1f imf_line1;
  rgb_s2l(imb_line1, imf_line1);
  cv::imwrite("rbg_line.tif", imf_line1);
  cv::Mat3b line3(1, 256);
  for (int i_col = 0; i_col < imb_line1.cols; i_col += 1) {
    line3.at<cv::Vec3b>(0, i_col) = cv::Vec3b(i_col, i_col, i_col);
  }
  cv::Mat3f imf_line3;
  rgb_s2l(line3, imf_line3);
  cv::imwrite("rbg_line3.png", line3);
}