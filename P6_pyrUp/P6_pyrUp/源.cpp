#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat dstImg1,dstImg2;
	imshow("ԭͼ", img);
	pyrUp(img, dstImg1, Size(img.cols * 2, img.rows * 2));
	pyrDown(img, dstImg2, Size(img.cols / 2, img.rows / 2));
	imshow("����ȡ��", dstImg1);
	imshow("����ȡ��", dstImg2);
	waitKey(0);
	return 0;
}