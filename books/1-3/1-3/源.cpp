#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout << "What is your name?";
	string name;
	cin >> name;
	cout << "hello," << name << endl << "And what is yours?";
	cin >> name;
	cout << "hello," << name << "; nice to meet you too!" << endl;
	return 0;
}