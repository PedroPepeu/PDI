#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <opencv2/opencv.hpp>
#include <utility>

class ImageProcessor {
public:
    void processImage(cv::Mat& inputImage, cv::Point seed, int n);
};

#endif // IMAGE_PROCESSOR_H
