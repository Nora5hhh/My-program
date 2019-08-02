#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	VideoCapture capture(0);
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("读取视频", frame);
		waitKey(30);
		if (frame.empty())
			break;
	}
	return 0;
	//程序失败，是因为根本就没有读进去
}