#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat srcImg = imread("F:/3.png");
	Mat tempImg, dstImg1, dstImg2;
	tempImg = srcImg;
	imshow("原图", srcImg);
	resize(tempImg, dstImg1, Size(tempImg.cols / 2, tempImg.rows / 2));
	//这样会得到原图4倍大小的输出
	//resize(tempImg, dstImg2, Size(tempImg.cols * 2, tempImg.rows * 2), 0.5, 0.5, INTER_AREA);
	//这样会得到原图四分之一大小的输出
	resize(tempImg, dstImg2, Size(0, 0), 0.5, 0.5, INTER_AREA);
	imshow("效果图1", dstImg1);
	imshow("效果图2", dstImg2);
	waitKey(0);
	return 0;
}