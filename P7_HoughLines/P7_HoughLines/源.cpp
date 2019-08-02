#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/4.png");
	Mat tempImg, dst;
	Canny(img, tempImg, 50, 200, 3);
	//转dst为彩色图
	cvtColor(tempImg, dst, COLOR_GRAY2BGR);
	//创建浮点型矢量结构lines，用于存放得到的线段矢量集合
	vector<Vec2f> lines;
	//用灰度图像进行霍夫变换
	HoughLines(tempImg, lines, 1, CV_PI / 180, 150, 0, 0);
	//依次在图中绘制出每条线段
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(dst, pt1, pt2, Scalar(55, 100, 195), 1, LINE_AA);
	}
	imshow("原图", img);
	imshow("效果图", dst);
	waitKey(0);
	return 0;
}