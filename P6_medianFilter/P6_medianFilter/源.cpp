#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("F:/1.jpg");
	Mat out;
	imshow("原图", img);
	//medianBlur(img, out, 7);
	//imshow("中值滤波后图", out);
	bilateralFilter(img, out, 7, 25, 25 / 2);
	//第三个参数d，表示过滤过程中每个像素邻域的直径
	//颜色空间滤波器的sigma值，这个参数值越大表明像素邻域内有越宽广的颜色混合到一起
	imshow("双边滤波后图", out);
	waitKey(0);
	return 0;
}