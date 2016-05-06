#include"Area.h"
#include<iostream>
using namespace std;

int main()
{
	Calculate calculate;

	cout << "Pleas input Radius:";
	cin >> calculate.rad;

	if (calculate.rad <= 0)
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "Area is " << calculate.cal(calculate.rad) << endl;
	}

	return 0;
}