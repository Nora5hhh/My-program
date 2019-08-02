#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/1.jpg");
	//namedWindow("Ô­Í¼", WINDOW_NORMAL);
	//namedWindow("ÂË²¨ºóÍ¼", WINDOW_NORMAL);
	Mat out;
	//boxFilter(img, out, -1,Size(5,5));
	//blur(img, out, Size(5, 5));
	GaussianBlur(img, out, Size(5, 5),0,0);
	imshow("Ô­Í¼", img);
	imshow("ÂË²¨ºóÍ¼", out);
	waitKey(0);
	return 0;
}