#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/1.jpg");
	Mat out;
	imshow("ԭͼ", img);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	//erode(img, out, element);
	dilate(img, out, element);
	imshow("��ʴ��ͼ", out);
	waitKey(0);
	return 0;
}