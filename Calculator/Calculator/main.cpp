#include<iostream> 
#include<string>
#include<queue>
#include<stdlib.h>
#include"Calculator.h"
using namespace std;

int main(int argc, char* argv[])
{
	Calculation calculation;
	Scan scan;
	string strData1;
	string strData2;
	strData1 = argv[1];
	queue<string>queue;
	if (strData1 == "-a")
	{
		strData2 == argv[2];		
		cout << strData2;
		queue = scan.ToStringQueue(strData2);
		cout << "= " << calculation.ToCalculate(queue) << endl;
	}
	else
	{
		queue = scan.ToStringQueue(strData1);
		cout << calculation.ToCalculate(queue) << endl;
	}
	system("pause");
	return 0;
}
