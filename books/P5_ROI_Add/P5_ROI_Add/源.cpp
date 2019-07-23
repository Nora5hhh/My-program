#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("F:/1.jpg");
	Mat ROI_Img, dstImg;
	Mat logoImg = imread("F:/logo.jpg");
	imshow("原图", srcImg);
	ROI_Img = srcImg(Rect(900, 1000, logoImg.cols, logoImg.rows));

	//掩模的方法
	Mat logoimg = imread("F:/logo.jpg");
	Mat mask = imread("F:/logo.jpg", 0);
	logoimg.copyTo(ROI_Img, mask);
	
	//创建输出图像
	//addWeighted(ROI_Img, 0.5, logoImg, 0.5, 0., dstImg);
	//imshow("添加后图", dstImg);

	//addWeighted(ROI_Img, 0.5, logoImg, 0.5, 0., ROI_Img);

	namedWindow("添加后图", WINDOW_NORMAL);
	imshow("添加后图", srcImg);
	
	waitKey(0);
	return 0;
}