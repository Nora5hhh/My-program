#include<iostream>
using namespace std;

int main()
{
	int input_1, input_2;
	cout << "Please enter the value of the first number:";
	cin >> input_1;
	cout << endl << "Please enter the value of the second number:";
	cin >> input_2;
	if (input_1 > input_2)
		cout << endl << "The first number is bigger." << endl;
	if (input_1 <= input_2)
	{
		if(input_1<input_2)
			cout << endl << "The second number is bigger." << endl;
		else
			cout << endl << "These two numbers are equal." << endl;
	}
	return 0;
}