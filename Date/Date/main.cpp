#include<iostream>
#include"date.h"
using namespace std;

int main()
{
	Date date;
	while (cin >> date.year >> date.month >> date.day)
	{
		if (date.year == 0 && date.month == 0 && date.day == 0)
		{
			break;
		}
		date.count(date.day, date.month, date.year);
	}
}