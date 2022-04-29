#include "chap05.h"

Mat brightness1(Mat src) {
	return src + 100;
}

Mat brightness2(Mat src) {


	Mat dst(src.rows, src.cols, src.type());
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			int v = src.at<uchar>(j, i) + 100;
			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;
		}
	}

	return dst;
}

Mat brightness3(Mat src) {


	Mat dst(src.rows, src.cols, src.type());
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
		}
	}

	return dst;
}

void on_brightness(int pos, void *userdata) {
	Mat src = *(Mat*)userdata;
	imshow("dst",src + pos);
}

Mat contrast(Mat src) {
	return src + (src - 128 ) * 1.f;
}

Mat clacGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1; // 채널, 차원
	const int histSize[] = { 256 };
	float grayLevel[] = { 0, 256 };
	const float* ranges[] = { grayLevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;

}

Mat getGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1,256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i,0)*100/histMax)), Scalar(0));
	}

	return imgHist;

}


Mat getGrayHistStretchingImage(Mat src) {
	double gmin, gmax;
	minMaxLoc(src, &gmin, &gmax);

	return (src - gmin) * 255 / (gmax - gmin);
}

Mat getequalizeHistImage(Mat src) {
	Mat dst;
	equalizeHist(src, dst);
	return dst;
}