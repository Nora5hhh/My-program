#include<iostream>
using namespace std;

int main()
{
	int s[7] = {1,3,5,4,1,2,6};
	int temp;
	
	for (int j = 0; j < 7; j++)
	{
		bool flag = false;
		for (int i = 0; i < 7-j-1; i++)
		{
			if (s[i] > s[i + 1])
			{
				temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
	cout << "the string is:";
	for (int i = 0; i < 7; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	return 0;
}