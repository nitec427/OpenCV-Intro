#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

namespace po {
	namespace fo {
		int x = 5;
	}
}

int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgDil, imgErode;
	Mat blurredImg;
	Mat imgCanny; // -> Used for edge detection
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, blurredImg, Size(3, 3), 3, 0);
	// For edge detection, most of the time developers use blur effect.
	Canny(blurredImg, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDil, kernel);
	imshow("Image", img);
	imshow("Grayed Image", imgGray);
	imshow("Blurred Image", blurredImg);
	imshow("Dilated Image", imgCanny);
	imshow("Eroded Image", imgDil);
	waitKey(0);

}