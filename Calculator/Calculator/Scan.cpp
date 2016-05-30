#include<iostream>
#include<string>
#include<queue>
#include<cctype>
#include<fstream>
#include"Calculator.h"
using namespace std;

string Scan::Open(char *in)
{
	string temp;
	fstream file;
	file.open(in);
	file >> temp;
	return temp;
}


queue<string>Scan::ToStringQueue(string input)
{
	while (!m_quQueue.empty())
	{
		m_quQueue.pop();
	}
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
			trans += input[i];
			if (!isdigit(input[i + 1]) && input[i + 1] != '.')
			{
				m_quQueue.push(trans);
				trans = "";
				continue;
			}
		}
		else//接收到的是符号 
		{
			if (input[i] != '=')
			{
				trans = input[i];
				m_quQueue.push(trans);//直接进队 
				trans = "";
			}
			else continue;
		}
	}
	return m_quQueue;
}