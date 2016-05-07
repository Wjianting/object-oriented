#include<iostream> 
#include<string>
#include<queue>
#include<cctype>
#include"Calculator.h"
using namespace std;


queue<string>Scan::ToStringQueue(string input)
{
	if (input[0] == '-')
	{
		string t;
		t += '0';
		m_quQueue.push(t);
	}
	for (int i = 0; i < input.length(); i++)//扫描整个string. 
	{
		if (isdigit(input[i]) || input[i] == '.')//如果扫描到数字,对整个数字进行处理. 
		{
			if (input[i] == '.')
			{
				i++;//如果接收到小数点,不计数,直接接收下一个数字. 
			}


			trans += input[i];
			if (!isdigit(input[i + 1]))
			{
				m_quQueue.push(trans);
				continue;
			}
		}
		else//接收到的是符号 
		{
			trans = input[i];
			m_quQueue.push(trans);//直接进队 
			trans = "";
		}
	}
	return m_quQueue;
}


void Print::ToOutput1(double answer, string exp)
{
	cout << exp << "= " << answer << endl;
}

void Print::ToOutput2(double answer)
{
	cout << answer << endl;
}


