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
				continue;
			}
		}
		else//���յ����Ƿ��� 
		{
			trans = input[i];
			m_quQueue.push(trans);//ֱ�ӽ��� 
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


