#include<iostream>
#include<string>
#include<queue>
#include<cctype>
#include<fstream>
#include"Calculator.h"
using namespace std;

string Scan::Open(string in)
{
	string temp;
	ifstream ifs(in);
	cin >> temp;
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
	for (int i = 0; i < input.length(); i++)//ɨ������string. 
	{
		if (isdigit(input[i]) || input[i] == '.')//���ɨ�赽����,���������ֽ��д���. 
		{
			if (input[i] == '.')
			{
				i++;//������յ�С����,������,ֱ�ӽ�����һ������. 
			}


			trans += input[i];
			if (!isdigit(input[i + 1]))
			{
				m_quQueue.push(trans);
				trans = "";
				continue;
			}
		}
		else//���յ����Ƿ��� 
		{
			if (input[i] != '=')
			{
				trans = input[i];
				m_quQueue.push(trans);//ֱ�ӽ��� 
				trans = "";
			}
			else continue;
		}
	}
	return m_quQueue;
}