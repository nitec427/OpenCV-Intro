#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	//The size of the image is the first 2 parameter.
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	//imshow("Image", img);
	circle(img, Point(256, 256), 155, Scalar(0, 70, 255), FILLED, 5);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 296), Point(392, 286), Scalar(255, 255, 255), 10);
	putText(img, "OpenCV Coding", Point(137, 262), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255), 2);
	imshow("Image", img);
	waitKey(0);

	
}