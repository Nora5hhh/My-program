#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("F:/1.jpg");
	Mat ROI_Img, dstImg;
	Mat logoImg = imread("F:/logo.jpg");
	imshow("ԭͼ", srcImg);
	ROI_Img = srcImg(Rect(900, 1000, logoImg.cols, logoImg.rows));

	//��ģ�ķ���
	Mat logoimg = imread("F:/logo.jpg");
	Mat mask = imread("F:/logo.jpg", 0);
	logoimg.copyTo(ROI_Img, mask);
	
	//�������ͼ��
	//addWeighted(ROI_Img, 0.5, logoImg, 0.5, 0., dstImg);
	//imshow("��Ӻ�ͼ", dstImg);

	//addWeighted(ROI_Img, 0.5, logoImg, 0.5, 0., ROI_Img);

	namedWindow("��Ӻ�ͼ", WINDOW_NORMAL);
	imshow("��Ӻ�ͼ", srcImg);
	
	waitKey(0);
	return 0;
}