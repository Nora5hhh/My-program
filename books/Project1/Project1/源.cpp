#include<iostream>
#include<vector>
#include<string>
using namespace std;

//����ṹ��
struct Student_info
{
	string name;
	double midterm, final;
	vector<double> homework;
};

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;

}
