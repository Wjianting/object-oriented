#include<iostream> 
#include<string>
#include<queue>
#include<stdlib.h>
#include"Calculator.h"
using namespace std;

int main(int argc, char* argv[])
{
	Scan scan;
	Print print;

	cout << "请输入表达式" << endl;
	string input;
	cin >> input;

	queue<string>queue = scan.ToStringQueue(input);

	print.ToOutput(queue);
	system("pause");
	return 0;
}
