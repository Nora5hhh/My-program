#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	imshow("ԭͼ", img);
	Rect ccomp;
	floodFill(img, Point(10, 50), Scalar(155, 255, 55),&ccomp,Scalar(10,10,10),Scalar(20,20,20));
	imshow("Ч��ͼ", img);
	waitKey(0);
	return 0;
}