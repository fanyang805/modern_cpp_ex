// #include <iostream>
// // #include <opencv2/imgcodecs.hpp>
// // #include <opencv2/opencv.hpp>

// #include <opencv2/core.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/imgcodecs.hpp>

// using namespace cv;

// int main() {
//   //   std::string image_path = cv::samples::findFile("starry_night.jpg");
//   //   cv::Mat i1 = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
//   //   cv::Mat_<uint8_t> i2 = cv::imread(image_path, cv::IMREAD_GRAYSCALE);

//   //   if (i1.empty()) {
//   //     std::cout << "Could not read the image: " << image_path <<
//   std::endl;
//   //     return 1;
//   //   }

//   //   std::cout << i1.type() << " " << i2.type() << std::endl;

//   //   const std::string window_name{"Window"};
//   //   cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
//   //   cv::imshow(window_name, i1);
//   //   cv::waitKey();
//   //   return 0;

//   std::string image_path = samples::findFile("starry_night.jpg");
//   Mat img = imread(image_path, IMREAD_COLOR);
//   if (img.empty()) {
//     std::cout << "Could not read the image: " << image_path << std::endl;
//     return 1;
//   }
//   imshow("Display window", img);
//   int k = waitKey(0); // Wait for a keystroke in the window
//   if (k == 's') {
//     imwrite("starry_night.png", img);
//   }
//   return 0;
// }

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
int main() {
  //   std::cout << cv::OPENCV_SAMPLES_DATA_PATH_HINT;
  std::string image_path = samples::findFile("starry_night.jpg");
  std::cout << "path is " << image_path << std::endl;
  Mat img = imread(image_path, IMREAD_COLOR);
  if (img.empty()) {
    std::cout << "Could not read the image: " << image_path << std::endl;
    return 1;
  }
  imshow("Display window", img);
  int k = waitKey(0); // Wait for a keystroke in the window
  if (k == 's') {
    imwrite("starry_night.png", img);
  }
  return 0;
}
