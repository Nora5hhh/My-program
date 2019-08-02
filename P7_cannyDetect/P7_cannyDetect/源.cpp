#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

#define WINDOW_NAME "canny_detect"
Mat src, dst,gray,cdst;
int threshold1 = 3, threshold2;

static void on_canny(int, void*)
{
	blur(gray, dst, Size(3, 3));
	Canny(dst, dst, threshold1, threshold2 * 3, 3);
	cdst = Scalar::all(0);
	//使用dst作为掩模，将原图拷到目标图中
	imshow("ty1", dst);
	src.copyTo(cdst,dst);
	//gray.copyTo(cdst,dst);
	imshow(WINDOW_NAME, cdst);
}

int main()
{
	src = imread("F:/3.png");
	cvtColor(src, gray, COLOR_BGR2GRAY);
	cdst.create(src.size(), src.type());
	namedWindow(WINDOW_NAME);
	createTrackbar("阈值", WINDOW_NAME, &threshold1, 100, on_canny);
	on_canny(0, 0);
	waitKey(0);
	return 0;
}