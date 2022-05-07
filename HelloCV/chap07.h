#pragma once

#include "main.h"

Mat filter_embossing(Mat img);
void filter_blurring(Mat img);
void filter_blurring_gaussian(Mat img);
void filter_sharpen(Mat img);
void noise_gaussian(Mat img);
void filter_bilateral(Mat img);