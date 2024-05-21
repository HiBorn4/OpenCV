#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

// Function to perform dilation and erosion
void dilate_erode(Mat& image) {
    // Define square and circular structuring elements
    Mat square_kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    Mat circular_kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));

    // Perform dilation
    Mat dilated_square, dilated_circular;
    dilate(image, dilated_square, square_kernel);
    dilate(image, dilated_circular, circular_kernel);

    // Perform erosion
    Mat eroded_square, eroded_circular;
    erode(image, eroded_square, square_kernel);
    erode(image, eroded_circular, circular_kernel);

    // Save the results
    imwrite("dilated_square.jpg", dilated_square);
    imwrite("dilated_circular.jpg", dilated_circular);
    imwrite("eroded_square.jpg", eroded_square);
    imwrite("eroded_circular.jpg", eroded_circular);
}

int main(int argc, char** argv) {
    // Check if the input image path is provided
    if (argc != 2) {
        cout << "Usage: ./morphology_operations <image_path>" << endl;
        return -1;
    }

    // Read the input image
    Mat input_image = imread(argv[1], IMREAD_GRAYSCALE);
    if (input_image.empty()) {
        cout << "Could not read the image: " << argv[1] << endl;
        return -1;
    }

    // Perform dilation and erosion
    dilate_erode(input_image);

    cout << "Dilation and erosion operations completed successfully." << endl;

    return 0;
}
