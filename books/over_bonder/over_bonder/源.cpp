#include<iostream>
using namespace std;

int main() {
	int i = 0;
	int arr[4];
	arr[3] = 0;
	for (; i <= 3; i++) {
		arr[i] = 0;
		cout << "hello world!" << endl;
		cout << &arr[i] << endl;
	}
	return 0;
}