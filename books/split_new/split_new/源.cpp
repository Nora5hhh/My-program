#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//�հ��ַ�����true
bool space(char c)
{
	return isspace(c);
}

//Ϊ�հ��ַ��򷵻�false
bool not_space(char c) {
	return !isspace(c);
}

//�ַ����Կհ��ַ��ָ�
vector<string> split(const string& s) {
	typedef string::const_iterator iter;
	iter i = s.begin();
	vector<string> res;
	while (i!=s.end())
	{
		//�����㷨���ҵ����ϵ�����ֵ��Ԫ��λ�ø���i
		i = find_if(i, s.end(), not_space);
		iter j = find_if(i, s.end(), space);
		if (i != s.end())
		{
			res.push_back(string(i, j));
		}
		i = j;
	}
	return res;
}

int main()
{
	string s;
	cout << "Please enter the string:";
	getline(cin, s);
	//cin >> s;
	vector<string> res;
	res = split(s);
	cout << endl;
	for (int i = 0; i != res.size(); i++)
	{
		cout << res[i] << endl;
	}
	
	return 0;
}