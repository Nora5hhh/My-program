#include<iostream>
#include<vector>
#include<string>
using namespace std;

//编写纵向连接子函数
vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
	vector<string> temp = top;
	for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); it++)
	{
		//it指向bottom的一个元素，对该元素进行调用时，需要调用间接引用运算符*访问该元素
		//*被用于一个迭代器时，会返回一个左值，这个左值就是迭代器所指元素
		temp.push_back(*it);
	}
	//下面这句与上面for循环一个意思
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

