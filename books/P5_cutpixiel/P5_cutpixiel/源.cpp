#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void PixelRelease(Mat& srcImg, Mat& dstImg, int div)
{
	int row = srcImg.rows;
	int col = srcImg.cols*srcImg.channels();
	dstImg = srcImg.clone();
	for (int i = 0; i < row; i++)
	{
		//指向data第i行的第一个元素
		uchar* data = dstImg.ptr<uchar>(i);
		for (int j = 0; j < col; j++)
		{
			data[j] = data[j] / div * div + div / 2;
		}
	}
}

int main()
{
	Mat srcImg,dstImg;
	srcImg = imread("F:/1.jpg");
	imshow("原图", srcImg);
	//int div = 10;
	double time0 = getTickCount();
	PixelRelease(srcImg, dstImg, 32);
	double time1 = getTickCount();
	double time = time1 - time0;
	imshow("像素缩减后", dstImg);
	cout << "用时为：" << time << endl;
	waitKey(0);
	return 0;
}