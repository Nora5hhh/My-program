#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/6.jpg");
	Mat dstImg;
	cvtColor(img, dstImg, COLOR_BGR2GRAY);
	namedWindow("灰度图", WINDOW_NORMAL);
	imshow("灰度图", dstImg);
	equalizeHist(dstImg, dstImg);
	namedWindow("直方图均衡化后图", WINDOW_NORMAL);
	imshow("直方图均衡化后图", dstImg);
	waitKey(0);
	return 0;
}