#include<iostream> 
#include<string>
#include<queue>
#include<cctype>
#include"Calculator.h"
using namespace std;


queue<string>Scan::ToStringQueue(string input)
{


	for (int i = 0; i < input.length(); i++)//扫描整个string. 
	{
		if (isdigit(input[i]) || input[i] == '.')//如果扫描到数字,对整个数字进行处理. 
		{
			if (input[i] == '.')
			{
				i++;//如果接收到小数点,不计数,直接接收下一个数字. 
			}

			length += 1;

			if (length >= 10)
			{
				if (!m_quQueue.empty())
				m_quQueue.pop();//当数字长度超标，清除数据 

				cout << "数字长度超标！" << endl;

				return m_quQueue;
				break;
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


void Print::ToOutput(queue<string>queue)
{
	string Output;
	while (!queue.empty())
	{
		Output = queue.front();
		cout << Output << endl;
		queue.pop();
	}
}
