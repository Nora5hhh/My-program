#include<iostream>
using namespace std;

int main()
{
	int s[] = { 4,5,6,3,2,1 };
	int temp;
	bool flag;
	for (int i = 0; i < 6; i++)
	{
		int mindex = i;
		flag = false;
		for (int j = i + 1; j < 6; j++)
		{
			if (s[j] < s[mindex])
			{
				mindex = j;
				flag = true;
			}	
		}
		if (!flag)
			break;
		temp = s[i];
		s[i] = s[mindex];
		s[mindex] = temp;
	}
	for (int i = 0; i < 6; i++)
		cout << s[i] << " ";
	cout << endl;
	return 0;
}