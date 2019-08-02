#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/5.png");
	Mat tempImg, dst;
	imshow("原始图", img);
	//转为灰度图并进行图像平滑
	cvtColor(img, tempImg, COLOR_BGR2GRAY);
	GaussianBlur(tempImg, tempImg, Size(9, 9), 2, 2);
	//霍夫圆变换
	vector<Vec3f> circles;
	HoughCircles(tempImg, circles, HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);
	//依次画圆
	for (size_t i = 0; i < circles.size(); i++)
	{
		//参数定义,cvRound将浮点数舍为最接近的整数
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//绘制圆心
		circle(img, center, 2, Scalar(0, 255, 0), -1, 8, 0);
		//绘制圆轮廓
		circle(img, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}
	imshow("效果图", img);
	waitKey(0);
	return 0;
}