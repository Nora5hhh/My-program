#include<iostream>
using namespace std;

int main()
{
	int s[] = { 4,5,6,1,3,2 };
	int value;
	for (int i = 1; i < 6; i++)
	{
		value = s[i];
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (s[j] > value)
			{
				s[j + 1] = s[j];
			}
			else
			{
				break;
			}
		}
		s[j + 1] = value;
	}
	for (int i = 0; i < 6; i++)
		cout << s[i] << " ";
	cout << endl;
	return 0;
}