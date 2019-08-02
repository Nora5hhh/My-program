#include<opencv2/opencv.hpp>
using namespace cv;

int g_nThresholdValue = 100;
int g_ThresholdType = 3;
Mat srcImg, g_grayImg, g_dstImg;
#define WINDOW_NAME "阈值窗口"

static void on_ThresHold(int, void*);

int main()
{
	srcImg = imread("F:/3.png");
	cvtColor(srcImg, g_grayImg, COLOR_BGR2GRAY);
	imshow("原图", srcImg);
	//需要先加一个窗口才能实现进度条
	namedWindow(WINDOW_NAME);
	createTrackbar("阈值", WINDOW_NAME, &g_nThresholdValue, 255, on_ThresHold);
	on_ThresHold(0, 0);
	waitKey(0);
	return 0;
}

//回调函数
static void on_ThresHold(int, void*)
{
	threshold(srcImg, g_dstImg, g_nThresholdValue, 255, g_nThresholdValue);
	imshow(WINDOW_NAME, g_dstImg);
}