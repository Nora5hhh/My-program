#include<iostream>
#include<cctype>  //isspace()的头文件
#include<vector>
#include<string>
using namespace std;

vector<string> split(const string& s) {
	vector<string> res;
	typedef vector<string>::size_type string_size;
	string_size i = 0;
	//字符串循环未到最后时循环继续
	while (i != s.size())
	{
		//i负责检测空白字符
		while (i != s.size() && isspace(s[i]))
		{
			++i;
		}
		string_size j = i;
		//j检测非空字符
		while (j != s.size() && !isspace(s[j]))
		{
			++j;
		}
		//将两个空白字符间的字符串输入给res作为其元素
		if (i != j)
		{
			res.push_back(s.substr(i, j - i));
		}
		//寻找下一个非空字符串
		i = j;
	}
	return res;
}

int main()
{
	string s;
	//getline定义在string头文件中，它能读输入直到行尾
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

