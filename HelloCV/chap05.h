#pragma once

#include "main.h"

Mat brightness1(Mat src);
Mat brightness2(Mat src);
Mat brightness3(Mat src);
void on_brightness(int pos, void *userdata);
Mat contrast(Mat src);
Mat clacGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);
Mat getGrayHistStretchingImage(Mat src);
Mat getequalizeHistImage(Mat src);