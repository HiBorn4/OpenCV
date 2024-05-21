#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: ./bilateral_filtering <image_path>" << endl;
        return -1;
    }

    // Read the input image
    Mat inputImage = imread(argv[1], IMREAD_COLOR);
    if (inputImage.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat grayImage;
    cvtColor(inputImage, grayImage, COLOR_BGR2GRAY);

    // Apply bilateral filtering using OpenCV function
    Mat resultOpenCV;
    double sigma_r = 50; // Sigma for range filter
    double sigma_s = 50; // Sigma for spatial filter
    bilateralFilter(grayImage, resultOpenCV, -1, sigma_r, sigma_s);

    // Custom implementation of bilateral filtering
    Mat resultCustom = grayImage.clone();
    int windowSize = 5; // Window size for filtering
    double sigmaSpace = 50; // Sigma for spatial filter
    double sigmaRange = 50; // Sigma for range filter
    int halfWindowSize = windowSize / 2;

    for (int y = halfWindowSize; y < grayImage.rows - halfWindowSize; y++) {
        for (int x = halfWindowSize; x < grayImage.cols - halfWindowSize; x++) {
            double sum = 0.0;
            double weightSum = 0.0;

            for (int i = -halfWindowSize; i <= halfWindowSize; i++) {
                for (int j = -halfWindowSize; j <= halfWindowSize; j++) {
                    int currentX = x + j;
                    int currentY = y + i;

                    double intensityDiff = grayImage.at<uchar>(currentY, currentX) - grayImage.at<uchar>(y, x);
                    double spatialWeight = exp(-(i * i + j * j) / (2 * sigmaSpace * sigmaSpace));
                    double rangeWeight = exp(-(intensityDiff * intensityDiff) / (2 * sigmaRange * sigmaRange));
                    double weight = spatialWeight * rangeWeight;

                    sum += weight * grayImage.at<uchar>(currentY, currentX);
                    weightSum += weight;
                }
            }

            resultCustom.at<uchar>(y, x) = cv::saturate_cast<uchar>(sum / weightSum);
        }
    }

    // Calculate absolute sum of the difference between OpenCV and custom result
    double absSum = cv::norm(resultOpenCV, resultCustom, NORM_L1);

    // Save the results in the same directory
    fs::path imagePath(argv[1]);
    string filename = imagePath.stem().string();

    string resultOpenCVPath = filename + "_openCV_result.jpg";
    string resultCustomPath = filename + "_custom_result.jpg";

    imwrite(resultOpenCVPath, resultOpenCV);
    imwrite(resultCustomPath, resultCustom);

    cout << "Results saved: " << resultOpenCVPath << " and " << resultCustomPath << endl;
    cout << "Absolute sum of the difference between OpenCV and custom result: " << absSum << endl;

    return 0;
}
