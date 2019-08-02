#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat grat_x, grat_y,gray,dst;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Scharr(gray, grat_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grat_x, grat_x);
	Scharr(gray, grat_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grat_y, grat_y);
	addWeighted(grat_x, 0.5, grat_y, 0.5, 0, dst);
	imshow("Ð§¹ûÍ¼", dst);
	waitKey(0);
	return 0;
}
