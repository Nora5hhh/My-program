#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat gray, dst;
	//高斯滤波
	GaussianBlur(img, img, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(img, gray, COLOR_BGR2GRAY);
	//核为3的拉普拉斯
	Laplacian(gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	//转化为8位图像
	convertScaleAbs(dst, dst);
	imshow("拉普拉斯边缘检测效果图", dst);
	waitKey(0);
	return 0;
}