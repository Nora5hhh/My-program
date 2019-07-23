#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	//�Ҷ�ͼ��
	Mat srcImg = imread("F:/1.jpg",0);
	if (!srcImg.data)
	{
		cout << "��ȡͼƬʧ�ܣ�" << endl;
		return -1;
	}
	namedWindow("ԭʼͼ��", WINDOW_NORMAL);
	imshow("ԭʼͼ��", srcImg);
	int m, n;
	//��չ���󵽺��ʵĳߴ�
	m = getOptimalDFTSize(srcImg.rows);
	n = getOptimalDFTSize(srcImg.cols);
	//��չ��Ϊ��չ������������ֵ����ʼֵΪ0
	Mat padded;
	copyMakeBorder(srcImg, padded, 0, m - srcImg.rows, 0, n - srcImg.cols, BORDER_CONSTANT, Scalar::all(0));
	//Ϊʵ�����鲿����洢�ռ�
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);
	//����Ҷ�任
	dft(complexI, complexI);
	//ʵ�����鲿�ֿ�
	split(complexI, planes);
	//ʵ���鲿���ֵ
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImg = planes[0];
	magnitudeImg += Scalar::all(1);
	//�����˲�
	log(magnitudeImg, magnitudeImg);
	//�ü��õ�ԭʼͼ���С
	magnitudeImg = magnitudeImg(Rect(0, 0, magnitudeImg.cols&-2, magnitudeImg.rows&-2));

	//��Ƶ���ĸ���������ı�λ��,ʹԭ����ͼ������
	int cx = magnitudeImg.cols / 2;
	int cy = magnitudeImg.rows / 2;
	
	Mat q0(magnitudeImg, Rect(0, 0, cx, cy));//����
	Mat q1(magnitudeImg, Rect(cx, 0, cx, cy));//����
	Mat q2(magnitudeImg, Rect(0, cy, cx, cy));//����
	Mat q3(magnitudeImg, Rect(cx, cy, cx, cy));//����
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
	
	//��һ��
	normalize(magnitudeImg, magnitudeImg, 0, 1, NORM_MINMAX);
	namedWindow("Ƶ�׷�ֵ", WINDOW_NORMAL);
	imshow("Ƶ�׷�ֵ", magnitudeImg);
	waitKey(0);
	return 0;
}