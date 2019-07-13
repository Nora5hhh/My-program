#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//空白字符返回true
bool space(char c)
{
	return isspace(c);
}

//为空白字符则返回false
bool not_space(char c) {
	return !isspace(c);
}

//字符串以空白字符分割
vector<string> split(const string& s) {
	typedef string::const_iterator iter;
	iter i = s.begin();
	vector<string> res;
	while (i!=s.end())
	{
		//泛型算法，找到符合第三个值的元素位置赋给i
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