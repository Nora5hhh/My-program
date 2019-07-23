#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("F:/1.jpg");
	vector<Mat> channels;
	Mat ROI_Img;
	Mat imageBlueChannel;
	Mat imageGreenChannel;
	Mat imageRedChannel;
	// 把一个3通道图像转换成3个单通道图像
	split(srcImg, channels);//分离色彩通道
	imageBlueChannel = channels.at(0);
	imageGreenChannel = channels.at(1);
	imageRedChannel = channels.at(2);
	//三个分量R、G、B因为是单通道图像，所以只能显示为灰度图。
	//如果要想显示出颜色来，应该用三通道图像来显示，比如显示R，我们就让G和B通道的数值为0或255。
	//显示彩色的B分量
	vector<Mat> mbgr(3);
	Mat bk1(srcImg.size(), CV_8UC1, Scalar(0));   //像素为0
	//表示了矩阵中元素的类型以及矩阵的通道个数，它是一系列的预定义的常量，其命名规则为CV_ + (位数）+（数据类型）+（通道数）。
	Mat imageB(srcImg.size(), CV_8UC3);
	//显示bgr三色图像中的blue通道  可以修改mbgr【1】或者mbgr【2】的值  
	mbgr[0] = channels[0];
	mbgr[1] = bk1;
	mbgr[2] = bk1;
	merge(mbgr, imageB);
	imshow("imageB", imageB);
	waitKey(0);
	return 0;
}