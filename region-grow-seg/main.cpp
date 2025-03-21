#include <opencv2/opencv.hpp>
#include <iostream>
#include "image_processor.h"

using namespace cv;
using namespace std;

Mat img;
ImageProcessor imgProcessor;

void onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_LBUTTONDOWN) {
        cout << "Mouse clicked at: (" << x << ", " << y << ")" << endl;
        
        Point clickedPixel(x, y);
        imgProcessor.processImage(img, clickedPixel, 30);  // Threshold `n = 30`

        imshow("Black and White Map", img);
    }
}

int main() {
    Mat image = imread("./image/img001.png");

    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    int bgSize = 1000;
    img = Mat::zeros(bgSize, bgSize, CV_8UC3);

    Mat resizedImage;
    resize(image, resizedImage, Size(bgSize, bgSize));
    resizedImage.copyTo(img(Rect(0, 0, resizedImage.cols, resizedImage.rows)));

    namedWindow("Black and White Map");
    setMouseCallback("Black and White Map", onMouse, NULL);

    imshow("Black and White Map", img);
    waitKey(0);

    return 0;
}
