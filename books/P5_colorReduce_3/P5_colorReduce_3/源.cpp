#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void colorReduce(Mat& srcImg, Mat& dstImg, int div)
{
	dstImg = srcImg.clone();
	int row = dstImg.rows;
	int col = dstImg.cols;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			dstImg.at<Vec3b>(i, j)[0] = dstImg.at<Vec3b>(i, j)[0] / div * div + div / 2;
			dstImg.at<Vec3b>(i, j)[1] = dstImg.at<Vec3b>(i, j)[1] / div * div + div / 2;
			dstImg.at<Vec3b>(i, j)[2] = dstImg.at<Vec3b>(i, j)[2] / div * div + div / 2;
		}
	}
}

int main()
{
	Mat srcImg, dstImg;
	srcImg = imread("F:/1.jpg");
	imshow("原图", srcImg);
	double time0 = getTickCount();
	colorReduce(srcImg, dstImg, 32);
	double time1 = getTickCount();
	double time = time1 - time0;
	imshow("颜色缩减后", dstImg);
	cout << "花费时间为：" << time << endl;
	waitKey(0);
	return 0;
}