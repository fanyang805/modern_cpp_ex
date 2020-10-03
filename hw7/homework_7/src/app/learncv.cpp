#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// k-means
int main() {

  cv::Mat projectedPointsImage =
      cv::Mat(512, 512, CV_8UC3, cv::Scalar::all(255));

  int nReferenceCluster = 10;
  int nSamplesPerCluster = 100;

  int N = nReferenceCluster * nSamplesPerCluster; // number of samples
  int n = 10;                                     // dimensionality of data

  // fill the data points
  // create n artificial clusters and randomly seed 100 points around them

  cv::Mat referenceCenters(nReferenceCluster, n, CV_32FC1);

  // std::cout << referenceCenters << std::endl;
  cv::randu(referenceCenters, cv::Scalar::all(0), cv::Scalar::all(512));
  // std::cout << "FILLED:" << "\n" << referenceCenters << std::endl;

  cv::Mat points = cv::Mat::zeros(N, n, CV_32FC1);
  cv::randu(points, cv::Scalar::all(-20),
            cv::Scalar::all(20)); // seed points around the center

  for (int j = 0; j < nReferenceCluster; ++j) {
    cv::Scalar clusterColor =
        cv::Scalar(rand() % 255, rand() % 255, rand() % 255);
    // cv::Mat & clusterCenter = referenceCenters.row(j);
    for (int i = 0; i < nSamplesPerCluster; ++i) {
      // creating a sample randomly around the artificial cluster:
      int index = j * nSamplesPerCluster + i;
      // samplesRow += clusterCenter;
      for (int k = 0; k < points.cols; ++k) {
        points.at<float>(index, k) += referenceCenters.at<float>(j, k);
      }

      // projecting the 10 dimensional clusters to 2 dimensions:
      cv::circle(
          projectedPointsImage,
          cv::Point(points.at<float>(index, 0), points.at<float>(index, 1)), 2,
          clusterColor, -1);
    }
  }

  cv::Mat labels;
  cv::Mat centers;
  int k = 10; // searched clusters in k-means

  cv::kmeans(
      points, k, labels,
      cv::TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 1000, 0.001),
      10, cv::KMEANS_PP_CENTERS, centers);

  for (int j = 0; j < centers.rows; ++j) {
    std::cout << centers.row(j) << std::endl;
    cv::circle(projectedPointsImage,
               cv::Point(centers.at<float>(j, 0), centers.at<float>(j, 1)), 30,
               cv::Scalar::all(0), 2);
  }

  cv::imshow("projected points", projectedPointsImage);
  //   cv::imwrite("C:/StackOverflow/Output/KMeans.png", projectedPointsImage);
  cv::waitKey(0);
  return 0;
}