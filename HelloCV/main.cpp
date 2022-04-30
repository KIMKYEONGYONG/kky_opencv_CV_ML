#include "main.h"
#include "chap05.h"
#include "chap06.h"

int main() {

	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img = myImageRead("lenna256.bmp",IMREAD_GRAYSCALE);
	Mat src = myImageRead("square.bmp",IMREAD_GRAYSCALE);

	if (img.empty()) {
		cerr << "Image load failed " << endl;
		return -1;
	}

	if (src.empty()) {
		cerr << "Image load failed " << endl;
		return -1;
	}

	imshow("img", img);
	imshow("src", src);


	// arithmetic(img, src);

	logical(img, src);

	/*
	Æ®·¢ ¹Ù
	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&img);
	on_brightness(0, (void*)&img);
	*/

	/* 
	Histogram
	imshow("srchist", getGrayHistImage(clacGrayHist(img)));

	Mat dst = getequalizeHistImage(img);
	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(clacGrayHist(dst)));
	*/




	waitKey(0);



	return 0;
}

Mat myImageRead(String filename , int flag) {
	return imread(filename, flag);
}