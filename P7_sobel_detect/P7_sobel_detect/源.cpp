#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/3.png");
	Mat x_grat, y_grat, dst;
	Mat gray;
	//��ԭͼת��Ϊ�Ҷ�ͼ��
	cvtColor(img, gray, COLOR_BGR2GRAY);
	if (img.empty())
	{
		cout << "empty!" << endl;
		return -1;
	}
	//x�����ݶ�ֵ
	Sobel(gray, x_grat, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	//���ݶ�ֵ�����ֵ�����Ĳ���Ϊ���š�ȡ����ֵ��ת��Ϊ�޷���8λ
	convertScaleAbs(x_grat, x_grat);
	imshow("x�����ݶ�ֵ", x_grat);

	Sobel(gray, y_grat, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(y_grat, y_grat);
	imshow("y�����ݶ�ֵ", y_grat);
	//Ȩ�ؼӺ͵õ����ͼ��
	addWeighted(x_grat, 0.5, y_grat, 0.5, 0, dst);
	imshow("Ч��ͼ", dst);
	waitKey(0);
	return 0;
}