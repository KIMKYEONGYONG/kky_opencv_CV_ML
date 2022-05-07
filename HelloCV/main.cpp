#include "chap05.h"
#include "chap06.h"
#include "chap07.h"

int main() {

	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img = myImageRead("lenna256.bmp",IMREAD_GRAYSCALE);
	// Mat src = myImageRead("square.bmp",IMREAD_GRAYSCALE);

	if (img.empty()) {
		cerr << "Image load failed " << endl;
		return -1;
	}

	imshow("img", img);
	


	// arithmetic(img, src);

	//logical(img, src);

	/*
	Æ®·¢ ¹Ù
	displayTrackBar("dst",img);
	*/

	/* 
	Histogram
	viewHist(img);
	*/

	//Mat dst = filter_embossing(img);
	//imshow("dst", dst);

	//filter_blurring(img);

	//filter_blurring_gaussian(img);

	// filter_sharpen(img);
	
	// noise_gaussian(img);

	/*
	Mat noise(img.size(), CV_32SC1);
	randn(noise, 0, 5);
	add(img, noise, img, Mat(), CV_8U);

	Mat dst1;
	GaussianBlur(img, dst1, Size(), 5);

	Mat dst2;
	bilateralFilter(img, dst2, -1, 10, 5);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	*/

	int num = (int)(img.total() * 0.1);
	for (int i = 0; i < num; i++) {
		int x = rand() % img.cols;
		int y = rand() % img.rows;
		img.at<uchar>(y, x) = (i % 2) * 255;
	}

	Mat dst1;
	GaussianBlur(img, dst1, Size(), 1);

	Mat dst2;
	medianBlur(img, dst2, 3);

	imshow("dst1", dst1);
	imshow("dst2", dst2);


	waitKey(0);



	return 0;
}

Mat myImageRead(String filename , int flag) {
	return imread(filename, flag);
}

void displayTrackBar(String windowname,Mat img) {
	namedWindow(windowname);
	createTrackbar("Brightness", windowname, 0, 100, on_brightness, (void*)&img);
	on_brightness(0, (void*)&img);
}

void viewHist(Mat img) {
	imshow("srchist", getGrayHistImage(clacGrayHist(img)));

	Mat dst = getequalizeHistImage(img);
	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(clacGrayHist(dst)));
}