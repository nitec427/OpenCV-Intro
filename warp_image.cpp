#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

// We determine the width and height of the outcome and we can give any value

// I think what's going under the hood is the matrix which converts the src image points to dst points is created with getPerspective function.

//Then, the very matrix is used for the transformation in the warpPerspective (src, dest, matrix, aand the location)
float w = 250, h = 350;
Mat matrix, imgWarp;
//int main() {
//	string path = "Resources/cards.jpg";
//	Mat img = imread(path);
//	//The function we are going to use requires the use of 2 precision float numbers.
//	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
//	Point2f dst[4] = { {0.0f,0.0f}, {w, 0.0f}, {0.0f, h}, {w,h} };
//	matrix = getPerspectiveTransform(src, dst);
//	warpPerspective(img, imgWarp, matrix, Point(w, h));
//	imshow("Image", img);
//	imshow("Warped Image", imgWarp);
//	waitKey(0);
//}

int main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Point2f src[4] = { {776,109},{1019,83},{845,359},{1116,330} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img,imgWarp, matrix, Point(w,h));

	for (int i = 0; i < 4; i++) {
		//Get the corner points from src array and insert circles with 10 dimater to the corners. 
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}
	imshow("Warped Image", imgWarp);
	imshow("Image", img);
	waitKey(0);
}