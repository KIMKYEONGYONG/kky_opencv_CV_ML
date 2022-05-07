#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat myImageRead(String filename, int flag);
void displayTrackBar(String windowname, Mat img);
void viewHist(Mat img);