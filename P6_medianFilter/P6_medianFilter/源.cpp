#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("F:/1.jpg");
	Mat out;
	imshow("ԭͼ", img);
	//medianBlur(img, out, 7);
	//imshow("��ֵ�˲���ͼ", out);
	bilateralFilter(img, out, 7, 25, 25 / 2);
	//����������d����ʾ���˹�����ÿ�����������ֱ��
	//��ɫ�ռ��˲�����sigmaֵ���������ֵԽ�����������������Խ������ɫ��ϵ�һ��
	imshow("˫���˲���ͼ", out);
	waitKey(0);
	return 0;
}