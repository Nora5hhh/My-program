#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/4.png");
	Mat tempImg, dst;
	Canny(img, tempImg, 50, 200, 3);
	cvtColor(tempImg, dst, COLOR_GRAY2BGR);
	vector<Vec4i> lines;
	HoughLinesP(tempImg, lines, 1, CV_PI / 180, 80, 50, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, LINE_AA);
	}
	imshow("ԭͼ", img);
	imshow("Ч��ͼ", dst);
	waitKey(0);
	return 0;
}