#include<iostream>
using namespace std;

class Date
{
public:
	int day, month, year;
	void count(int day, int month, int year);
	bool judge(int year);
};

void Date::count(int day, int month,int year)
{
	int days1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, count = 0;
	for (i = 0; i < month - 1;i++)
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