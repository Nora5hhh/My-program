#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat girl = imread("F:/1.jpg");
	namedWindow("ԭͼ", WINDOW_NORMAL);
	imshow("ԭͼ", girl);
	Mat logo = imread("F:/logo.jpg");
	namedWindow("logo", WINDOW_NORMAL);
	imshow("logo", logo);
	//����girlROIʵ�����Ǵ�����logoһ����С��ͼƬ
	Mat girlROI = girl(Rect(900, 1000, logo.cols, logo.rows));
	//girlROI��logo����ͼ���
	addWeighted(girlROI, 0.7, logo, 0.3, 3, girlROI);
	namedWindow("��logo��ͼ", WINDOW_NORMAL);
	imshow("��logo��ͼ", girl);
	imwrite("imwriteд��ͼƬ.jpg", girl);
	imshow("girlͼ", girlROI);
	waitKey();
	return 0;
}
