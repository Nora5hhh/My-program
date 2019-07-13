#include<iostream>
#include<string>
#include<vector>
using namespace std;

//计算字符串数组元素的最大长度
int width(vector<string> s) {
	vector<string>::size_type m = s.size(),i=0;
	int maxlen = 0;
	for (i = 0; i != m; i++)
	{
		maxlen = (maxlen >= s[i].size()) ? maxlen : s[i].size();
	}
	return maxlen;
}

//将两个字符串数组横向连接
vector<string> hcat(vector<string> left, vector<string> right) {
	int left_len, right_len;
	left_len = width(left)+1;
	vector<string> res;
	int i = 0,j=0;
	while (i!=left.size()||j!=right.size())
	{
		string s;
		if (i!=left.size())
		{
			s = left[i++];
			s+=string((left_len - s.size()), ' ');
		}
		
		if (j!=right.size())
		{
			s += right[j++];
		}
		res.push_back(s);
	}
	return res;
}

int main()
{
	vector<string> left, right;
	string x;
	int i = 0;
	while (i!=2)
	{
		cout << "the element of left is:";
		cin >> x;
		left.push_back(x);
		i++;
	}
	cin.clear();
	cin.ignore();
	i = 0;
	while (i != 2)
	{
		cout << "the element of right is:";
		cin >> x;
		right.push_back(x);
		i++;
	}
	vector<string> res;
	res = hcat(left, right);
	cout << endl << "The result is:" << endl;
	for (int i = 0; i != res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}