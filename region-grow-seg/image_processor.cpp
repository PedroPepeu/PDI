#include "image_processor.h"
#include <iostream>
#include <queue>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int getColor(const Point& p, const Mat& img) {
    return img.at<uchar>(p.y, p.x);  // Assuming a grayscale image
}

void ImageProcessor::processImage(cv::Mat& inputImage, Point seed, int n) {
    if (inputImage.empty()) {
        cerr << "Error: Input image is empty or not found!" << endl;
        return;
    }

    int width = inputImage.cols;
    int height = inputImage.rows;

    // Convert image to grayscale if it's not already
    if (inputImage.channels() == 3) {
        cvtColor(inputImage, inputImage, COLOR_BGR2GRAY);
    }

    queue<Point> pixelQueue;
    pixelQueue.push(seed);
    int seedColor = getColor(seed, inputImage);
    
    // Keep track of visited pixels
    Mat visited = Mat::zeros(height, width, CV_8U);
    visited.at<uchar>(seed.y, seed.x) = 1;

    while (!pixelQueue.empty()) {
        Point curPixel = pixelQueue.front();
        pixelQueue.pop();

        // Change pixel color to white (or another color)
        inputImage.at<uchar>(curPixel.y, curPixel.x) = 255;

        // 4-connectivity neighbors
        vector<Point> neighbors = {
            Point(curPixel.x + 1, curPixel.y),
            Point(curPixel.x - 1, curPixel.y),
            Point(curPixel.x, curPixel.y + 1),
            Point(curPixel.x, curPixel.y - 1)
        };

        for (const Point& neighbor : neighbors) {
            if (neighbor.x >= 0 && neighbor.x < width &&
                neighbor.y >= 0 && neighbor.y < height &&
                visited.at<uchar>(neighbor.y, neighbor.x) == 0) {
                
                int neighborColor = getColor(neighbor, inputImage);
                bool colorCongruent = abs(neighborColor - seedColor) < n;

                if (colorCongruent) {
                    pixelQueue.push(neighbor);
                    visited.at<uchar>(neighbor.y, neighbor.x) = 1;
                }
            }
        }
    }
}
