#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// <summary>
/// Loading image from a file
/// </summary>
/// <returns></returns>
int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);
 
}

/// <summary>
/// Loading image from a file
/// </summary>
/// <returns></returns>
int main() {
	//string path = "Resources/test_video.mp4";
	//If you want to use a video, you can use the path of the video. Otherwise, you can use your external cameras with their corresponding ID.
	// 0 -> first cam etc.
	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(200);
	}

}
