#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

static void on_ContrastValue(int, void *);

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImg, g_dstImg;

int main()
{
	g_srcImg = imread("F:/1.jpg");
	g_dstImg = Mat::zeros(g_srcImg.size(), g_srcImg.type());
	g_nBrightValue = 80;
	g_nContrastValue = 80;
	namedWindow("Ч��ͼ����");
	//����������
	createTrackbar("�Աȶ�", "Ч��ͼ����", &g_nContrastValue, 300, on_ContrastValue);
	createTrackbar("����", "Ч��ͼ����", &g_nBrightValue, 300, on_ContrastValue);
	//���ú����ı�Աȶ�������
	on_ContrastValue(g_nContrastValue, 0);
	waitKey(0);
	return 0;
}

static void on_ContrastValue(int, void *)
{
	namedWindow("ԭʼͼ����", 1);
	double time0 = getTickCount();
	//������ͨ����ÿһ������ֵ�任
	for (int y = 0; y < g_srcImg.rows; y++)
	{
		for (int x = 0; x < g_srcImg.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstImg.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImg.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		}
	}
	//������ʱ
	double time1 = getTickCount();
	double time = time1 - time0;
	cout << "��ʱΪ��" << time << endl;
	imshow("ԭʼͼ����", g_srcImg);
	imshow("Ч��ͼ����", g_dstImg);
}