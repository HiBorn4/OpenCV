#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat preprocessImage(const Mat& image) {
    // Resize the image to 720x480
    Mat resizedImage;
    resize(image, resizedImage, Size(720, 480));
    
    // Convert the image to grayscale
    Mat grayImage;
    cvtColor(resizedImage, grayImage, COLOR_BGR2GRAY);
    
    return grayImage;
}

Mat laplacianOfGaussian(const Mat& image, double sigma) {
    // Apply Gaussian blur
    Mat blurredImage;
    GaussianBlur(image, blurredImage, Size(0, 0), sigma);
    
    // Apply Laplacian operator
    Mat laplacian;
    Laplacian(blurredImage, laplacian, CV_64F);
    
    return laplacian;
}

Mat zeroCrossings(const Mat& laplacian) {
    // Find zero crossings
    Mat zeroCrossings = Mat::zeros(laplacian.size(), CV_8U);
    for (int i = 1; i < laplacian.rows - 1; ++i) {
        for (int j = 1; j < laplacian.cols - 1; ++j) {
            double neighbors[8] = {
                laplacian.at<double>(i - 1, j),
                laplacian.at<double>(i + 1, j),
                laplacian.at<double>(i, j - 1),
                laplacian.at<double>(i, j + 1),
                laplacian.at<double>(i - 1, j - 1),
                laplacian.at<double>(i - 1, j + 1),
                laplacian.at<double>(i + 1, j - 1),
                laplacian.at<double>(i + 1, j + 1)
            };
            bool hasZeroCrossing = false;
            for (int k = 0; k < 8; ++k) {
                if (std::signbit(laplacian.at<double>(i, j)) != std::signbit(neighbors[k])) {
                    hasZeroCrossing = true;
                    break;
                }
            }
            if (hasZeroCrossing) {
                zeroCrossings.at<uchar>(i, j) = 255;
            }
        }
    }
    return zeroCrossings;
}

void detectEdges(const string& imagePath, double sigma) {
    // Read the image
    Mat image = imread("images/white_rose.png");
    if (image.empty()) {
        cerr << "Error: Unable to read image." << endl;
        return;
    }
    
    // Preprocess the image
    Mat grayImage = preprocessImage(image);
    
    // Apply Laplacian of Gaussian
    Mat laplacian = laplacianOfGaussian(grayImage, sigma);
    
    // Find zero crossings
    Mat edges = zeroCrossings(laplacian);
    
    // Save the output image
    string outputImagePath = imagePath.substr(0, imagePath.find_last_of(".")) + "_edges.jpg";
    imwrite(outputImagePath, edges);
    cout << "Edge-detected image saved at: " << outputImagePath << endl;
}

int main() {
    string imagePath = "image.jpg";  // Path to the image
    double sigma = 1.4;  // Gaussian kernel standard deviation
    detectEdges(imagePath, sigma);
    return 0;
}
