#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat girl = imread("F:/1.jpg");
	namedWindow("原图", WINDOW_NORMAL);
	imshow("原图", girl);
	Mat logo = imread("F:/logo.jpg");
	namedWindow("logo", WINDOW_NORMAL);
	imshow("logo", logo);
	//创建girlROI实际上是创建和logo一样大小的图片
	Mat girlROI = girl(Rect(900, 1000, logo.cols, logo.rows));
	//girlROI与logo两幅图混合
	addWeighted(girlROI, 0.7, logo, 0.3, 3, girlROI);
	namedWindow("加logo后图", WINDOW_NORMAL);
	imshow("加logo后图", girl);
	imwrite("imwrite写的图片.jpg", girl);
	imshow("girl图", girlROI);
	waitKey();
	return 0;
}
