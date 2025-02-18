#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

using namespace cv;
using namespace std;
namespace fs = filesystem;

// Function to create an image based on pixel distribution
Mat createImageFromDistribution(const vector<int>& distribution) {
    // Find maximum value in the distribution
    int maxVal = *max_element(distribution.begin(), distribution.end());

    // Create a histogram
    Mat hist = Mat::zeros(Size(256, maxVal + 1), CV_8UC1);
    for (int i = 0; i < 256; ++i) {
        line(hist, Point(i, maxVal), Point(i, maxVal - distribution[i]), Scalar(255));
    }

    // Create a grayscale image
    Mat image(maxVal + 1, 256, CV_8UC1);
    cvtColor(hist, image, COLOR_GRAY2BGR);

    return image;
}

int main(int argc, char** argv) {
    // Given pixel distribution
    vector<int> pixelDistribution = {
        0, 0, 1, 0, 2, 0, 3, 1, 4, 4, 5, 9, 6, 16, 7, 76, 8, 165, 9, 318,
        10, 622, 11, 944, 12, 1473, 13, 1883, 14, 2449, 15, 3031, 16, 3574,
        17, 3917, 18, 4107, 19, 4191, 20, 4254, 21, 4249, 22, 4282, 23, 4308,
        24, 4139, 25, 4033, 26, 3973, 27, 4039, 28, 3903, 29, 3873, 30, 3847,
        31, 3655, 32, 3633, 33, 3474, 34, 3591, 35, 3605, 36, 3582, 37, 3696,
        38, 3766, 39, 3717, 40, 3535, 41, 3397, 42, 3381, 43, 3254, 44, 3232,
        45, 3317, 46, 3433, 47, 3471, 48, 3472, 49, 3381, 50, 3514, 51, 3484,
        52, 3925, 53, 4097, 54, 4360, 55, 4450, 56, 4239, 57, 4130, 58, 3954,
        59, 3558, 60, 3245, 61, 3119, 62, 3053, 63, 3114, 64, 2985, 65, 3011,
        66, 2883, 67, 2980, 68, 3029, 69, 3119, 70, 3207, 71, 3275, 72, 3449,
        73, 3285, 74, 3191, 75, 3324, 76, 3209, 77, 3104, 78, 2982, 79, 3029,
        80, 2915, 81, 2782, 82, 2689, 83, 2561, 84, 2463, 85, 2435, 86, 2354,
        87, 2203, 88, 2133, 89, 2076, 90, 2111, 91, 1856, 92, 1799, 93, 1685,
        94, 1665, 95, 1543, 96, 1466, 97, 1375, 98, 1303, 99, 1263, 100, 1190,
        101, 1153, 102, 1107, 103, 1044, 104, 1013, 105, 1001, 106, 880, 107,
        863, 108, 779, 109, 705, 110, 690, 111, 675, 112, 616, 113, 620, 114,
        570, 115, 526, 116, 459, 117, 409, 118, 397, 119, 342, 120, 326, 121,
        279, 122, 245, 123, 232, 124, 229, 125, 197, 126, 173, 127, 190, 128,
        228, 129, 197, 130, 196, 131, 161, 132, 215, 133, 180, 134, 180, 135,
        213, 136, 182, 137, 185, 138, 165, 139, 139, 140, 113, 141, 91, 142,
        74, 143, 70, 144, 68, 145, 54, 146, 60, 147, 45, 148, 40, 149, 57,
        150, 42, 151, 48, 152, 50, 153, 56, 154, 60, 155, 62, 156, 62, 157,
        61, 158, 60, 159, 84, 160, 76, 161, 85, 162, 67, 163, 75, 164, 85,
        165, 104, 166, 106, 167, 112, 168, 129, 169, 110, 170, 125, 171, 133,
        172, 155, 173, 155, 174, 150, 175, 138, 176, 183, 177, 164, 178, 184,
        179, 232, 180, 208, 181, 235, 182, 234, 183, 293, 184, 301, 185, 271,
        186, 299, 187, 311, 188, 347, 189, 404, 190, 439, 191, 440, 192, 442,
        193, 488, 194, 553, 195, 647, 196, 617, 197, 606, 198, 639, 199, 674,
        200, 711, 201, 708, 202, 730, 203, 715, 204, 663, 205, 671, 206, 715,
        207, 647, 208, 623, 209, 653, 210, 634, 211, 634, 212, 590, 213, 522,
        214, 536, 215, 574, 216, 592, 217, 636, 218, 611, 219, 648, 220, 636,
        221, 600, 222, 644, 223, 611, 224, 645, 225, 677, 226, 702, 227, 703,
        228, 716, 229, 742, 230, 701, 231, 756, 232, 739, 233, 773, 234, 839,
        235, 943, 236, 904, 237, 708, 238, 707, 239, 664, 240, 703, 241, 688,
        242, 728, 243, 643, 244, 656, 245, 539, 246, 493, 247, 387, 248, 269,
        249, 226, 250, 135, 251, 106, 252, 69, 253, 38, 254, 20, 255, 0
    };

    // Create the image from the given pixel distribution
    Mat referenceImage = createImageFromDistribution(pixelDistribution);

    // Get the directory path of the executable
    fs::path executablePath = fs::path(argv[0]);
    string directory = executablePath.parent_path().string();

    // Read the input image
    Mat inputImage = imread("images/IttigattiScene.jpg");

    // Check if images are loaded successfully
    if (inputImage.empty()) {
        cerr << "Error: Could not open or find the input image." << endl;
        return -1;
    }

    // Perform histogram matching
    Mat matchedImage;
    cvtColor(inputImage, matchedImage, COLOR_BGR2GRAY);
    equalizeHist(matchedImage, matchedImage);

    // Save images in the same directory
    imwrite(directory + "/inputImage.jpg", inputImage);
    imwrite(directory + "/referenceImage.jpg", referenceImage);
    imwrite(directory + "/matchedImage.jpg", matchedImage);

    // Display images
    imshow("Input Image", inputImage);
    imshow("Reference Image", referenceImage);
    imshow("Matched Image", matchedImage);
    waitKey(0);

    return 0;
}
