#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/5.png");
	Mat tempImg, dst;
	imshow("ԭʼͼ", img);
	//תΪ�Ҷ�ͼ������ͼ��ƽ��
	cvtColor(img, tempImg, COLOR_BGR2GRAY);
	GaussianBlur(tempImg, tempImg, Size(9, 9), 2, 2);
	//����Բ�任
	vector<Vec3f> circles;
	HoughCircles(tempImg, circles, HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);
	//���λ�Բ
	for (size_t i = 0; i < circles.size(); i++)
	{
		//��������,cvRound����������Ϊ��ӽ�������
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//����Բ��
		circle(img, center, 2, Scalar(0, 255, 0), -1, 8, 0);
		//����Բ����
		circle(img, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}
	imshow("Ч��ͼ", img);
	waitKey(0);
	return 0;
}