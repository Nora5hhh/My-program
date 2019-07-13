#include<iostream>
using namespace std;

//定义clock类，它有两个成员函数，三个对象
class Clock
{
public:
	void setTime(int newH = 0, int newM = 0, int newS = 0);
	void showTime();

private:
	int hour, minute, second;
};

void Clock::setTime(int newH,int newM,int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
}

void Clock::showTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
	Clock myClock;
	myClock.setTime(8, 30, 30);
	myClock.showTime();
	return 0;
}