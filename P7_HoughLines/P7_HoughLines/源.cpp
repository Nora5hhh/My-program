#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("F:/4.png");
	Mat tempImg, dst;
	Canny(img, tempImg, 50, 200, 3);
	//תdstΪ��ɫͼ
	cvtColor(tempImg, dst, COLOR_GRAY2BGR);
	//����������ʸ���ṹlines�����ڴ�ŵõ����߶�ʸ������
	vector<Vec2f> lines;
	//�ûҶ�ͼ����л���任
	HoughLines(tempImg, lines, 1, CV_PI / 180, 150, 0, 0);
	//������ͼ�л��Ƴ�ÿ���߶�
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(dst, pt1, pt2, Scalar(55, 100, 195), 1, LINE_AA);
	}
	imshow("ԭͼ", img);
	imshow("Ч��ͼ", dst);
	waitKey(0);
	return 0;
}