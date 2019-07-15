#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void colorReduce(Mat srcImg, Mat dstImg, int div)
{
	dstImg = srcImg.clone();
	Mat_<Vec3b>::iterator it = dstImg.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = dstImg.end<Vec3b>();
	for (; it < itend; it++)
	{
		(*it)[0] = (*it)[0] / div * div + div / 2;
		(*it)[1] = (*it)[1] / div * div + div / 2;
		(*it)[2] = (*it)[2] / div * div + div / 2;
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
	cout << "用时为：" << time << endl;
	imshow("颜色缩减后", dstImg);
	waitKey(0);
	return 0;
}