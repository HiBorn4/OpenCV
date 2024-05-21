#include <opencv2/opencv.hpp>
#include <iostream>
#include <queue>

using namespace cv;
using namespace std;

// Global variable to store the seed point
Point seedPoint;

// Mouse callback function
void onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_LBUTTONDOWN) {
        seedPoint = Point(x, y);
    }
}

// Function to perform region growing
void regionGrowing(Mat& image, Mat& mask, int threshold) {
    queue<Point> pointsQueue;
    pointsQueue.push(seedPoint);
    
    while (!pointsQueue.empty()) {
        Point currentPoint = pointsQueue.front();
        pointsQueue.pop();
        
        if (mask.at<uchar>(currentPoint) == 0) {
            mask.at<uchar>(currentPoint) = 255;
            
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int x = currentPoint.x + dx;
                    int y = currentPoint.y + dy;
                    
                    if (x >= 0 && x < image.cols && y >= 0 && y < image.rows) {
                        if (abs(image.at<uchar>(currentPoint) - image.at<uchar>(y, x)) < threshold) {
                            pointsQueue.push(Point(x, y));
                        }
                    }
                }
            }
        }
    }
}

// Function to perform boundary detection
void boundaryDetection(Mat& mask, Mat& boundary) {
    boundary = mask.clone();
    erode(mask, boundary, Mat());
    absdiff(mask, boundary, boundary);
}

// Function to perform thinning
void thinning(Mat& image) {
    threshold(image, image, 127, 255, THRESH_BINARY);
    Mat skel(image.size(), CV_8UC1, Scalar(0));
    Mat temp;
    Mat eroded;
    
    bool done;
    do {
        erode(image, eroded, Mat());
        dilate(eroded, temp, Mat());
        subtract(image, temp, temp);
        bitwise_or(skel, temp, skel);
        eroded.copyTo(image);
        done = (countNonZero(image) == 0);
    } while (!done);
    
    image = skel.clone();
}

int main(int argc, char** argv) {
    // Read the input image
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "Could not read the image." << endl;
        return -1;
    }

    // Create a window and display the image
    namedWindow("Image");
    imshow("Image", image);
    
    // Set the mouse callback function
    setMouseCallback("Image", onMouse);

    waitKey(0);

    // Perform region growing around the seed point
    Mat mask(image.size(), CV_8UC1, Scalar(0));
    regionGrowing(image, mask, 20);

    // Perform boundary detection
    Mat boundary;
    boundaryDetection(mask, boundary);

    // Perform thinning on the boundary
    thinning(boundary);

    // Save the output files
    imwrite("mask.png", mask);
    imwrite("boundary.png", boundary);

    return 0;
}
