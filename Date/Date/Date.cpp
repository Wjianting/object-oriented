#include<iostream>
#include"date.h"
using namespace std;

void Date::count(int day, int month, int year)
{
	int days1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, count = 0;
	for (i = 0; i < month - 1; i++)
	{
		if (judge(year))
		{
			count += days2[i];
		}
		else
		{
			count += days1[i];
		}
	}
	count += day;
	cout << count << endl;
}

bool Date::judge(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
