#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat srcImg = imread("F:/3.png");
	Mat tempImg, dstImg1, dstImg2;
	tempImg = srcImg;
	imshow("ԭͼ", srcImg);
	resize(tempImg, dstImg1, Size(tempImg.cols / 2, tempImg.rows / 2));
	//������õ�ԭͼ4����С�����
	//resize(tempImg, dstImg2, Size(tempImg.cols * 2, tempImg.rows * 2), 0.5, 0.5, INTER_AREA);
	//������õ�ԭͼ�ķ�֮һ��С�����
	resize(tempImg, dstImg2, Size(0, 0), 0.5, 0.5, INTER_AREA);
	imshow("Ч��ͼ1", dstImg1);
	imshow("Ч��ͼ2", dstImg2);
	waitKey(0);
	return 0;
}