// 4-connectivity

#include "image_processor.h"
#include <iostream>

bool checkPos(int xMapS, int yMapS, int xPos, int yPos, pair<int, int> seed, int n) {
	if(xPos < 0 || yPos < 0) return false;

	if(xPos > XMapS || yPos > yMapS) return false;

	bool colorCongruent = abs(getColor(make_pair(xMapS, yMapS)) - getColor(seed)) < n;

	return colorCongruent;
}

pair<int, int> processMouseClick(cv::Point mousePos) {
	std::cout << "Processing mouse click at: (" << mousePos.x << ", " << mousePos.y << ")" <<std::endl;
	return std::make_pair (mousePos.x, mousePos.y);
}

void ImageProcessor::processImage(const cv::Mat& InputImage) {
	
	if(inputImage.empty()) {
		std::cerr << "Error: Input image is empty or not found!" << std::endl;
		return;
	}

	int width = inputImage.cols;
	int height = inputImage.rows;

	pair<int, int> pixel_seed = processMouseClick();
	std::queue<std::pair<int,int>> pixel_q;

	while(!pixel_q.empty()) {
		cur_pixel = pixel_q.front();
		pixel_q.pop();
		// change the color of the current pixel change_color()
		
	}

	return 0;
}
