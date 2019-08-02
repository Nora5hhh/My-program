#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat dstImg1,dstImg2;
	imshow("原图", img);
	pyrUp(img, dstImg1, Size(img.cols * 2, img.rows * 2));
	pyrDown(img, dstImg2, Size(img.cols / 2, img.rows / 2));
	imshow("向上取样", dstImg1);
	imshow("向下取样", dstImg2);
	waitKey(0);
	return 0;
}