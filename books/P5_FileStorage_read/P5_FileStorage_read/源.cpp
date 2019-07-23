#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	//�ı�color��ɫ
	system("color 6F");
	//��ʼ��
	FileStorage fs2("test.yaml", FileStorage::READ);
	string data;
	fs2[ "calibrationDate" ] >> data;
	Mat cameraMatrix2, distCoeffs2;
	fs2["cameraMatrix"] >> cameraMatrix2;
	fs2["distCoeffs"] >> distCoeffs2;

	FileNode features = fs2["features"];
	FileNodeIterator it = features.begin(), it_end = features.end();
	int idx = 0;
	vector<uchar> lbpval;
	//ʹ��FileNodeIterator��������
	for (; it != it_end; idx++)
	{
		cout << "features #" << idx << ": ";
		cout << "x=" << (int)(*it)["x"] << ",y=" << (int)(*it)["y"] << ",lbp:(";
		(*it)["lbp"] >> lbpval;
		for (int i = 0; i < (int)lbpval.size(); i++)
			cout << " " << (int)lbpval[i];
		cout << ")" << endl;
	}
	fs2.release();
	cout << "�ļ���ȡ��ϣ��������������������";
	getchar();
	return 0;
}