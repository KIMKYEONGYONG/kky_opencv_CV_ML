#include "chap07.h"

Mat filter_embossing(Mat img) {
	float data[] = { -1,-1,0,-1,0,1,0,1,1 };
	Mat emboss(3, 3, CV_32FC1, data);

	Mat dst;
	filter2D(img, dst, -1, emboss, Point(-1,1), 128);

	return dst;
}

void  filter_blurring(Mat img) {
	Mat dst;
	for (int ksize = 3; ksize <= 7; ksize += 2) {
		blur(img, dst, Size(ksize, ksize));

		String desc = format("Mean : %dx%d", ksize, ksize);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}

}

void filter_blurring_gaussian(Mat img) {
	Mat dst;
	for (int sigma = 1; sigma <= 5; sigma++) {
		GaussianBlur(img, dst, Size(),(double)sigma);

		String text = format("sigma : %d", sigma);
		putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}
}

void filter_sharpen(Mat img) {
	
	for (int sigma = 1; sigma <= 5; sigma++) {
		Mat blurred;
		GaussianBlur(img, blurred, Size(), (double)sigma);

		float alpha = 1.f;
		Mat dst = (1 + alpha) * img - alpha * blurred;

		String text = format("sigma : %d", sigma);
		putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}
}

void noise_gaussian(Mat img) {

	for (int stddev = 10; stddev <= 30; stddev+=10) {
		Mat noise(img.size(), CV_32SC1);
		randn(noise, 0, stddev);

		Mat dst;
		add(img, noise, dst, Mat(), CV_8U);

		String text = format("stddev : %d", stddev);
		putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}
}