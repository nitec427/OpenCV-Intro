#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil, Mat img) {

	//contours -> { {Point(x1,y1)}, {}, {} }, vector of vector of points
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 5);
	//Color is purple and -1 designates printing all the contours
	for (int i = 0; i < contours.size(); i++) {
	
		int area = contourArea(contours[i]);
		cout << area << endl;
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		string ObjectType;
		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << endl;
			/* boundRect[i] = boundingRect(conPoly[i]);*/
			int objCor = (int)conPoly[i].size();
			if (objCor == 3)
				ObjectType = "Triangle";
			else if (objCor == 4)
				ObjectType = "Rectangle";
			else
				ObjectType = "Any other shape"
		};
		
	}
}

int main() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	
	//Preprocessing for the purposes of contour detection
	cvtColor(img, imgGray,COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);
	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilated", imgDil);*/
	waitKey(0);

	

}