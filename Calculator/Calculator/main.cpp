#include<iostream> 
#include<string>
#include<queue>
#include<stdlib.h>
#include"Calculator.h"
#pragma warning(disable:4996)
using namespace std;

int main(int argc, char* argv[])
{
	Calculation calculation;
	Scan scan;
	Print print;
	string strData1;
	string strData2;
	strData1 = argv[1];
	queue<string>queue;
	double answer;
	if (strData1 == "-a")
	{
		strData2 = argv[2];
		queue = scan.ToStringQueue(strData2);
		answer = calculation.ToCalculate(queue);
		print.ToOutput1(answer, argv[2]);
	}
	else if (strData1 == "-f")
	{
		freopen(argv[2], "r", stdin);
		freopen(argv[3], "w", stdout);
		string strData3;
		cin >> strData3;
		queue = scan.ToStringQueue(strData3);
		answer = calculation.ToCalculate(queue);
		print.ToOutput2(answer);
	}

	else
	{
		queue = scan.ToStringQueue(strData1);
		answer = calculation.ToCalculate(queue);
		print.ToOutput2(answer);
	}
	system("pause");
	return 0;
}
