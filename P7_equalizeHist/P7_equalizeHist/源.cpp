#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/6.jpg");
	Mat dstImg;
	cvtColor(img, dstImg, COLOR_BGR2GRAY);
	namedWindow("�Ҷ�ͼ", WINDOW_NORMAL);
	imshow("�Ҷ�ͼ", dstImg);
	equalizeHist(dstImg, dstImg);
	namedWindow("ֱ��ͼ���⻯��ͼ", WINDOW_NORMAL);
	imshow("ֱ��ͼ���⻯��ͼ", dstImg);
	waitKey(0);
	return 0;
}