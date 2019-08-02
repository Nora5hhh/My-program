#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

#define WINDOW_NAME1 "原始窗口"
#define WINDOW_NAME2 "warp后的窗口"
#define WINDOW_NAME3 "warp和rotate后的窗口"

int main()
{
	Mat src = imread("F:/3.png");
	imshow(WINDOW_NAME1, src);
	Mat dst_warp, dst_warp_rotate;
	dst_warp = Mat::zeros(src.size(), src.type());
	Point2f srcTriangle[3];
	Point2f dstTriangle[3];
	//dst与src的点,根据X与T求M
	srcTriangle[0] = Point2f(0, 0);
	srcTriangle[1] = Point2f(static_cast<float>(src.cols - 1), 0);
	srcTriangle[2] = Point2f(0, static_cast<float>(src.rows - 1));
	dstTriangle[0] = Point2f(0, static_cast<float>(src.rows*0.33));
	dstTriangle[1] = Point2f(static_cast<float>(src.cols*0.65), static_cast<float>(src.rows*0.35));
	dstTriangle[2] = Point2f(static_cast<float>(src.cols*0.15), static_cast<float>(src.rows*0.6));
	//2*3的矩阵
	Mat rowMat(2, 3, CV_32FC1);
	Mat warpMat(2, 3, CV_32FC1);
	warpMat = getAffineTransform(srcTriangle, dstTriangle);
	warpAffine(src, dst_warp, warpMat, dst_warp.size());
	imshow(WINDOW_NAME2, dst_warp);
	Point center = Point(dst_warp.cols / 2, dst_warp.rows / 2);
	double angle = -30.0;
	double scale = 0.8;
	rowMat = getRotationMatrix2D(center, angle, scale);
	warpAffine(dst_warp, dst_warp_rotate, rowMat, dst_warp_rotate.size());
	imshow(WINDOW_NAME3, dst_warp_rotate);
	waitKey(0);
	return 0;
}