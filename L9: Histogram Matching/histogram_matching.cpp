#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

// Function to perform histogram matching between two images
Mat histogramMatching(const Mat& inputImage, const Mat& referenceImage) {
    // Compute histograms
    Mat histInput, histReference;
    int histSize = 256; // Number of bins
    float range[] = { 0, 256 };
    const float* histRange = { range };
    calcHist(&inputImage, 1, 0, Mat(), histInput, 1, &histSize, &histRange, true, false);
    calcHist(&referenceImage, 1, 0, Mat(), histReference, 1, &histSize, &histRange, true, false);

    // Compute cumulative histograms
    Mat cumHistInput = Mat::zeros(histSize, 1, CV_32FC1);
    Mat cumHistReference = Mat::zeros(histSize, 1, CV_32FC1);
    float sumInput = 0, sumReference = 0;
    for (int i = 0; i < histSize; ++i) {
        sumInput += histInput.at<float>(i);
        cumHistInput.at<float>(i) = sumInput;

        sumReference += histReference.at<float>(i);
        cumHistReference.at<float>(i) = sumReference;
    }

    // Compute mapping
    Mat mapping(1, histSize, CV_8UC1);
    for (int i = 0; i < histSize; ++i) {
        int closestIntensity = 0;
        float minDiff = abs(cumHistInput.at<float>(i) - cumHistReference.at<float>(0));
        for (int j = 1; j < histSize; ++j) {
            float diff = abs(cumHistInput.at<float>(i) - cumHistReference.at<float>(j));
            if (diff < minDiff) {
                minDiff = diff;
                closestIntensity = j;
            }
        }
        mapping.at<uchar>(i) = closestIntensity;
    }

    // Apply mapping to input image
    Mat matchedImage;
    LUT(inputImage, mapping, matchedImage);

    return matchedImage;
}

int main() {
    // Read input and reference images
    Mat inputImage = imread("images/IttigattiScene.jpg", IMREAD_GRAYSCALE);
    Mat referenceImage = imread("images/BSTpedha.jpg", IMREAD_GRAYSCALE);

    // Check if images are loaded successfully
    if (inputImage.empty() || referenceImage.empty()) {
        cerr << "Error: Could not open or find the images." << endl;
        return -1;
    }

    // Specify window size for output images
    int windowSize = 600; // Change this value as needed

    // Resize images to specified window size
    resize(inputImage, inputImage, Size(windowSize, windowSize));
    resize(referenceImage, referenceImage, Size(windowSize, windowSize));

    // Perform histogram matching
    Mat matchedImage = histogramMatching(inputImage, referenceImage);

    // Resize matched image to specified window size
    resize(matchedImage, matchedImage, Size(windowSize, windowSize));

    // Save images in the same directory as the executable
    fs::path inputImagePath = fs::current_path() / "input_image.jpg";
    fs::path referenceImagePath = fs::current_path() / "reference_image.jpg";
    fs::path matchedImagePath = fs::current_path() / "matched_image.jpg";

    imwrite(inputImagePath.string(), inputImage);
    imwrite(referenceImagePath.string(), referenceImage);
    imwrite(matchedImagePath.string(), matchedImage);

    // Display images
    imshow("Input Image", inputImage);
    imshow("Reference Image", referenceImage);
    imshow("Matched Image", matchedImage);
    waitKey(0);

    return 0;
}
