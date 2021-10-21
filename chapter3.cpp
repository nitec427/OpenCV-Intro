#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCropped;

	cout << img.size() << endl;
	resize(img, imgResize, Size(), 0.5, 0.5);

	Rect roi(200, 100, 300, 300);
	imgCropped = img(roi);

	imshow("Original", img);
	imshow("Resized", imgResize);
	imshow("Cropped", imgCropped);
	waitKey(0);
}