#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    string image_path = "../images/example.jpeg";
    Mat original_image = imread(image_path, IMREAD_COLOR);
    resize(original_image, original_image, {500, 500});
    if (original_image.empty())
    {
        cout << "Could not load image" << endl;
        return -1;
    }
    int low_H = 170, low_S = 80, low_V = 50;
    int high_H = 180, high_S = 255, high_V = 255;

    Mat hsvImage, imageThreshold;

    cvtColor(original_image, hsvImage, COLOR_BGR2HSV);
    inRange(hsvImage, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), imageThreshold);
    Mat medianBlurImage, gaussianBlurImage;

    medianBlur(original_image, medianBlurImage, 9);
    GaussianBlur(original_image, gaussianBlurImage, Size(1, 1), 9, 9);

    imshow("Original Image", original_image);
    imshow("HSV Image", hsvImage);
    imshow("Image Threshold", imageThreshold);
    imshow("Median Blur Image", medianBlurImage);
    imshow("Gaussian Blur Image", gaussianBlurImage);
    waitKey(0);
    return 0;
}