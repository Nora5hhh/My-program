#include<iostream>
#include<cctype>  //isspace()��ͷ�ļ�
#include<vector>
#include<string>
using namespace std;

vector<string> split(const string& s) {
	vector<string> res;
	typedef vector<string>::size_type string_size;
	string_size i = 0;
	//�ַ���ѭ��δ�����ʱѭ������
	while (i != s.size())
	{
		//i������հ��ַ�
		while (i != s.size() && isspace(s[i]))
		{
			++i;
		}
		string_size j = i;
		//j���ǿ��ַ�
		while (j != s.size() && !isspace(s[j]))
		{
			++j;
		}
		//�������հ��ַ�����ַ��������res��Ϊ��Ԫ��
		if (i != j)
		{
			res.push_back(s.substr(i, j - i));
		}
		//Ѱ����һ���ǿ��ַ���
		i = j;
	}
	return res;
}

int main()
{
	string s;
	//getline������stringͷ�ļ��У����ܶ�����ֱ����β
	while (getline(cin,s))
	{
		vector<string> v = split(s);
		for (vector<string>::size_type i = 0; i != v.size(); i++)
		{
			cout << v[i] << endl;
		}
		return 0;
	}
}

