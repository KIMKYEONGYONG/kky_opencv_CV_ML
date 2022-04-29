#include "main.h"
#include "chap05.h"

int main() {

	cout << "Hello OpenCV " << CV_VERSION << endl;

	Mat img = myImageRead(IMREAD_GRAYSCALE);

	if (img.empty()) {
		cerr << "Image load failed " << endl;
		return -1;
	}

	namedWindow("src");
	imshow("src", img);
	/*
	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&img);
	on_brightness(0, (void*)&img);
	*/
	imshow("srchist", getGrayHistImage(clacGrayHist(img)));

	Mat dst = getequalizeHistImage(img);
	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(clacGrayHist(dst)));

	waitKey(0);



	return 0;
}

Mat myImageRead(int flag) {
	return imread("lenna.bmp", flag);
}