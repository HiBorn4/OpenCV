#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // Read the input image
    Mat image = imread("images/white_rose.png", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Unable to read image." << endl;
        return -1;
    }

    // Perform Gaussian blur to reduce noise
    Mat blurred;
    GaussianBlur(image, blurred, Size(3, 3), 0);

    // Perform Canny edge detection
    Mat edges;
    Canny(blurred, edges, 50, 150);

    // Perform Hough Transform to detect lines
    vector<Vec4i> lines;
    HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 50, 10);

    // Draw the detected lines on a blank image
    Mat result(image.size(), CV_8UC3, Scalar(255, 255, 255));
    for (size_t i = 0; i < lines.size(); i++) {
        Vec4i l = lines[i];
        line(result, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
    }

    // Save the result
    imwrite("result.jpg", result);
    cout << "Result saved as 'result.jpg'." << endl;

    return 0;
}
