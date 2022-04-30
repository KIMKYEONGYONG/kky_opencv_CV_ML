#include "chap06.h"


void arithmetic(Mat img, Mat src) {

	Mat dst1, dst2, dst3, dst4;
	add(img, src, dst1);
	addWeighted(img, 0.5, src, 0.5, 0, dst2);
	subtract(img, src, dst3);
	absdiff(img, src, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
}

void logical(Mat img, Mat src) {

	Mat dst1, dst2, dst3, dst4;
	bitwise_and(img, src, dst1);
	bitwise_or(img, src, dst2);
	bitwise_xor(img, src, dst3);
	bitwise_not(img, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
}