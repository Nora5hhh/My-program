#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/1.jpg");
	//namedWindow("ԭͼ", WINDOW_NORMAL);
	//namedWindow("�˲���ͼ", WINDOW_NORMAL);
	Mat out;
	//boxFilter(img, out, -1,Size(5,5));
	//blur(img, out, Size(5, 5));
	GaussianBlur(img, out, Size(5, 5),0,0);
	imshow("ԭͼ", img);
	imshow("�˲���ͼ", out);
	waitKey(0);
	return 0;
}