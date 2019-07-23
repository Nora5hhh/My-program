#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("F:/1.jpg");
	vector<Mat> channels;
	Mat ROI_Img;
	Mat imageBlueChannel;
	Mat imageGreenChannel;
	Mat imageRedChannel;
	// ��һ��3ͨ��ͼ��ת����3����ͨ��ͼ��
	split(srcImg, channels);//����ɫ��ͨ��
	imageBlueChannel = channels.at(0);
	imageGreenChannel = channels.at(1);
	imageRedChannel = channels.at(2);
	//��������R��G��B��Ϊ�ǵ�ͨ��ͼ������ֻ����ʾΪ�Ҷ�ͼ��
	//���Ҫ����ʾ����ɫ����Ӧ������ͨ��ͼ������ʾ��������ʾR�����Ǿ���G��Bͨ������ֵΪ0��255��
	//��ʾ��ɫ��B����
	vector<Mat> mbgr(3);
	Mat bk1(srcImg.size(), CV_8UC1, Scalar(0));   //����Ϊ0
	//��ʾ�˾�����Ԫ�ص������Լ������ͨ������������һϵ�е�Ԥ����ĳ���������������ΪCV_ + (λ����+���������ͣ�+��ͨ��������
	Mat imageB(srcImg.size(), CV_8UC3);
	//��ʾbgr��ɫͼ���е�blueͨ��  �����޸�mbgr��1������mbgr��2����ֵ  
	mbgr[0] = channels[0];
	mbgr[1] = bk1;
	mbgr[2] = bk1;
	merge(mbgr, imageB);
	imshow("imageB", imageB);
	waitKey(0);
	return 0;
}