#include<iostream>
#include<vector>
#include<string>
using namespace std;

//��д���������Ӻ���
vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
	vector<string> temp = top;
	for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); it++)
	{
		//itָ��bottom��һ��Ԫ�أ��Ը�Ԫ�ؽ��е���ʱ����Ҫ���ü�����������*���ʸ�Ԫ��
		//*������һ��������ʱ���᷵��һ����ֵ�������ֵ���ǵ�������ָԪ��
		temp.push_back(*it);
	}
	//�������������forѭ��һ����˼
	//temp.insert(temp.end(), bottom.begin(), bottom.end());
	return temp;
}

int main()
{
	vector<string> top, bottom;
	string x;
	int i = 0;
	while (i!=2)
	{
		cout << "The element of top is:";
		cin >> x;
		top.push_back(x);
		i++;
	}
	i = 0;
	cin.clear();
	cin.ignore();
	while (i!=2)
	{
		cout << "The element of top is:";
		cin >> x;
		bottom.push_back(x);
		i++;
	}
	
	vector<string> res;
	res = vcat(top, bottom);
	for (int i = 0; i != res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}

