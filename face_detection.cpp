#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// This library is important
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <string>

// Face Detection Basic Code

using namespace std;
using namespace cv;
int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) {
		cerr << "Problem has occurred" << endl;
	}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
	}

	imshow("Image", img);
	waitKey(0);
}