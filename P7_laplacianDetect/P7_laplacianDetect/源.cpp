#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat gray, dst;
	//��˹�˲�
	GaussianBlur(img, img, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(img, gray, COLOR_BGR2GRAY);
	//��Ϊ3��������˹
	Laplacian(gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	//ת��Ϊ8λͼ��
	convertScaleAbs(dst, dst);
	imshow("������˹��Ե���Ч��ͼ", dst);
	waitKey(0);
	return 0;
}