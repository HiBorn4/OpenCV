#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void findConnectedComponents(Mat& image, Mat& labels) {
    int numLabels = connectedComponents(image, labels, 8, CV_32S);
    cout << "Number of connected components: " << numLabels << endl;
}

void findComponentBoundaries(Mat& labels, Mat& boundaries) {
    // Convert labels to CV_8U data type
    Mat labels8U;
    labels.convertTo(labels8U, CV_8U);
    
    // Apply Canny edge detection
    Canny(labels8U, boundaries, 0, 255);
}

vector<int> findProminentComponents(Mat& labels) {
    vector<int> componentSizes(1e5, 0); // Assuming a maximum of 100,000 components
    vector<int> prominentComponents;
    
    for (int i = 0; i < labels.rows; i++) {
        for (int j = 0; j < labels.cols; j++) {
            int label = labels.at<int>(i, j);
            componentSizes[label]++;
        }
    }
    
    vector<pair<int, int>> sortedComponents;
    for (int i = 1; i < componentSizes.size(); i++) {
        sortedComponents.push_back({i, componentSizes[i]});
    }
    sort(sortedComponents.begin(), sortedComponents.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    
    for (int i = 0; i < min(10, (int)sortedComponents.size()); i++) {
        prominentComponents.push_back(sortedComponents[i].first);
    }
    
    return prominentComponents;
}

void displayProminentComponents(Mat& image, Mat& labels, vector<int>& prominentComponents) {
    for (int i = 0; i < prominentComponents.size(); i++) {
        Mat componentMask = Mat::zeros(image.size(), CV_8UC1);
        for (int r = 0; r < labels.rows; ++r) {
            for (int c = 0; c < labels.cols; ++c) {
                if (labels.at<int>(r, c) == prominentComponents[i]) {
                    componentMask.at<uchar>(r, c) = 255;
                }
            }
        }
        imshow("Prominent Component " + to_string(i + 1), componentMask);
    }
    waitKey(0);
}

int main() {
    // Read the input image
    // Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/barbara_gray.bmp", IMREAD_GRAYSCALE);
    // Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/BSTpedha.jpg", IMREAD_GRAYSCALE);
    // Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/flower.jpg", IMREAD_GRAYSCALE);
    // Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/IttigattiScene.jpg", IMREAD_GRAYSCALE);
    // Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/lena_gray.bmp", IMREAD_GRAYSCALE);
    // Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/noisyImage.png", IMREAD_GRAYSCALE);
    Mat image = imread("/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/images/white_rose.png", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Unable to read input image!" << endl;
        return -1;
    }
    
    // Threshold the image
    Mat binaryImage;
    threshold(image, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);
    
    // Find connected components
    Mat labels;
    findConnectedComponents(binaryImage, labels);
    
    // Find component boundaries
    Mat boundaries;
    findComponentBoundaries(labels, boundaries);
    
    // Find prominent components
    vector<int> prominentComponents = findProminentComponents(labels);
    
    // Display prominent components
    displayProminentComponents(binaryImage, labels, prominentComponents);
    
    return 0;
}
