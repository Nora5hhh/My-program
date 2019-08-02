#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat x_grat, y_grat, dst;
	Mat gray;
	//将原图转化为灰度图像
	cvtColor(img, gray, COLOR_BGR2GRAY);
	if (img.empty())
	{
		cout << "empty!" << endl;
		return -1;
	}
	//x方向梯度值
	Sobel(gray, x_grat, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	//将梯度值求绝对值，它的步骤为缩放、取绝对值、转化为无符号8位
	convertScaleAbs(x_grat, x_grat);
	imshow("x方向梯度值", x_grat);

	Sobel(gray, y_grat, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(y_grat, y_grat);
	imshow("y方向梯度值", y_grat);
	//权重加和得到输出图像
	addWeighted(x_grat, 0.5, y_grat, 0.5, 0, dst);
	imshow("效果图", dst);
	waitKey(0);
	return 0;
}