#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat map_x, map_y;
	Mat dst;
	dst.create(img.size(), img.type());
	map_x.create(img.size(), CV_32FC1);
	map_y.create(img.size(), CV_32FC1);
	//循环改变x与y的值
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			//x不变，y反转
			map_x.at<float>(i, j) = static_cast<float>(j);
			map_y.at<float>(i, j) = static_cast<float>(img.rows - i);
		}
	}
	remap(img, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
	imshow("效果图", dst);
	waitKey(0);
	return 0;
}