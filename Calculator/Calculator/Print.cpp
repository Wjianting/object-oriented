#include<iostream>
#include<string>
#include"Calculator.h"
#include<fstream>
using namespace std;

void Print::ToOutput(double answer, char *out)
{
	ofstream ofs(out);
	cout << answer << endl;
}

void Print::ToOutput(double answer)
{
	cout << answer << endl;
}

void Print::ToOutput(double answer, string exp)
{
	cout << exp << answer << endl;
}