#include<iostream> 
#include<string>
#include<queue>
#include<cctype>
#include"Calculator.h"
using namespace std;


queue<string>Scan::ToStringQueue(string input)
{


	for (int i = 0; i < input.length(); i++)//ɨ������string. 
	{
		if (isdigit(input[i]) || input[i] == '.')//���ɨ�赽����,���������ֽ��д���. 
		{
			if (input[i] == '.')
			{
				i++;//������յ�С����,������,ֱ�ӽ�����һ������. 
			}

			length += 1;

			if (length >= 10)
			{
				if (!m_quQueue.empty())
				m_quQueue.pop();//�����ֳ��ȳ��꣬������� 

				cout << "���ֳ��ȳ��꣡" << endl;

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
		else//���յ����Ƿ��� 
		{
			trans = input[i];
			m_quQueue.push(trans);//ֱ�ӽ��� 
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
