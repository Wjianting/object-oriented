#include<string>
#include<queue>
#include<cctype>
#include<stack>
#include<sstream>
#include"Calculator.h"

using namespace std;

int Calculation::priority(char x)//�Ƚ����ȼ�
{
	if (x == '+' || x == '-')
	{
		return 1;
	}
	else if (x == '*' || x == '/')
	{
		return 2;
	}
	else if (x == '(' || x == ')')
	{
		return 0;
	}
	else return 0;
}



void Calculation::compare(char m, string n, string q)
{
	char temp2 = n[0];
	if (Calculation::priority(m) >= Calculation::priority(temp2))//���ȼ���ջ��������Ľϸ߻���ȣ�Ҳ�������ѹ��ջ1
	{
		m_S2.push(q);
	}
	else//����ջ��Ԫ�ص�����ѹ��ջ2������ջ��Ԫ�ؼ����Ƚ�
	{
		m_S1.push(m_S2.top());
		m_S2.pop();
		if (!m_S2.empty())
		{
			compare(m, m_S2.top(), q);
		}
		else
		{
			string trans;
			trans += m;
			m_S2.push(trans);
		}
	}
}

double cal(double a, double b, char x)
{
	if (x == '+')
	{
		return a + b;
	}
	else if (x == '-')
	{
		return a - b;
	}
	else if (x == '*')
	{
		return a * b;
	}
	else if (x == '/')
	{
		if (b != 0)
		{
			return a / b;
		}
		else
		{
			printf("��������Ϊ�㣡");
			return 0;
		}
	}
	else return 0;
}



double Calculation::ToCalculate(queue<string>queue)
{
	int i;
	double num;
	string trans;
	char temp;
	string expression[101];
	for (i = 0; !queue.empty(); i++)//�����ʽ����string
	{
		expression[i] = queue.front();
		queue.pop();
	}
	i--;
	for (; i >= 0; i--)//��������ɨ����ʽ
	{
		trans = expression[i];
		temp = trans[0];
		if (!isdigit(temp) && temp != '(' && temp != ')')//����������
		{
			if (m_S2.empty() || m_S2.top() == ")")
			{
				m_S2.push(trans);//���ջ2�ջ���ջ	��Ϊ�����ţ�ֱ��ѹ��
			}

			else//������Ҫ��ջ��Ԫ�رȽ����ȼ�
			{
				compare(temp, m_S2.top(), trans);
			}
		}

		else if (temp == '(')/*����������ţ����ε���ջ1�������������ѹ��ջ2��
							 ֱ������������Ϊֹ����ʱ�������������*/
		{
			while (m_S2.top() != ")")
			{
				m_S1.push(m_S2.top());
				m_S2.pop();
			};
			m_S2.pop();
		}

		else if (temp == ')')//����������ţ�ֱ��ѹ��ջ2�У�
		{
			m_S2.push(trans);
		}

		else//���ִ����һ��ջ
		{
			m_S1.push(trans);
		}
		expression[i] = "";
	}

	while (!m_S1.empty())/*��ջ1ʣ�����������ε�����ѹ��ջ2��ջ2�м���׺
						 ���ʽ��Ӧ��ǰ׺���ʽ����*/
	{
		m_S2.push(m_S1.top());
		m_S1.pop();
	}
	string expression1[101];
	for (i = 0; !m_S2.empty(); i++)//��ջ�е���ı��ʽ����string�У���������ʼ���㡣
	{
		expression1[i] += m_S2.top();
		m_S2.pop();
	}
	int j = i;
	for (i = 0; i < j; i++)//��������ɨ����ʽ
	{
		if (isdigit(expression1[i][0]))//��������
		{
			stringstream stream(expression1[i]);
			stream >> num;
			m_S3.push(num);//ѹ��ջ��
			expression1[i] = "";
		}
		else//���������
		{
			double temp1, temp2, temp3;
			temp1 = m_S3.top(); m_S3.pop();
			temp2 = m_S3.top(); m_S3.pop();
			temp3 = cal(temp1, temp2, expression1[i][0]);//ȡ��ջ���������ֽ��м����ѹ��ջ��
			expression1[i] = "";
			m_S3.push(temp3);
		}
	}
	return m_S3.top();//���ջ�������־��Ǵ�
	m_S3.pop();
}