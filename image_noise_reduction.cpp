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
    imshow("Original Image", original_image);
    waitKey(0);
    return 0;
}