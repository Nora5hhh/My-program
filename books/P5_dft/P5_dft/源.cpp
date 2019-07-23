#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	//灰度图像
	Mat srcImg = imread("F:/1.jpg",0);
	if (!srcImg.data)
	{
		cout << "读取图片失败！" << endl;
		return -1;
	}
	namedWindow("原始图像", WINDOW_NORMAL);
	imshow("原始图像", srcImg);
	int m, n;
	//扩展矩阵到合适的尺寸
	m = getOptimalDFTSize(srcImg.rows);
	n = getOptimalDFTSize(srcImg.cols);
	//扩展并为扩展后的新像素添加值，初始值为0
	Mat padded;
	copyMakeBorder(srcImg, padded, 0, m - srcImg.rows, 0, n - srcImg.cols, BORDER_CONSTANT, Scalar::all(0));
	//为实部与虚部分配存储空间
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);
	//傅里叶变换
	dft(complexI, complexI);
	//实部与虚部分开
	split(complexI, planes);
	//实部虚部求幅值
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImg = planes[0];
	magnitudeImg += Scalar::all(1);
	//对数滤波
	log(magnitudeImg, magnitudeImg);
	//裁剪得到原始图像大小
	magnitudeImg = magnitudeImg(Rect(0, 0, magnitudeImg.cols&-2, magnitudeImg.rows&-2));

	//将频谱四个象限区域改变位置,使原点在图像中心
	int cx = magnitudeImg.cols / 2;
	int cy = magnitudeImg.rows / 2;
	
	Mat q0(magnitudeImg, Rect(0, 0, cx, cy));//左上
	Mat q1(magnitudeImg, Rect(cx, 0, cx, cy));//右上
	Mat q2(magnitudeImg, Rect(0, cy, cx, cy));//左下
	Mat q3(magnitudeImg, Rect(cx, cy, cx, cy));//右下
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
	
	//归一化
	normalize(magnitudeImg, magnitudeImg, 0, 1, NORM_MINMAX);
	namedWindow("频谱幅值", WINDOW_NORMAL);
	imshow("频谱幅值", magnitudeImg);
	waitKey(0);
	return 0;
}