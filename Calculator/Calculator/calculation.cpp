#include<string>
#include<queue>
#include<cctype>
#include<stack>
#include<sstream>
#include"Calculator.h"

using namespace std;

int Calculation::priority(char x)//比较优先级
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
	if (Calculation::priority(m) >= Calculation::priority(temp2))//优先级比栈顶运算符的较高或相等，也将运算符压入栈1
	{
		m_S2.push(q);
	}
	else//否则将栈顶元素弹出并压入栈2，将新栈顶元素继续比较
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
			printf("除数不能为零！");
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
	for (i = 0; !queue.empty(); i++)//将表达式传入string
	{
		expression[i] = queue.front();
		queue.pop();
	}
	i--;
	for (; i >= 0; i--)//从右至左扫描表达式
	{
		trans = expression[i];
		temp = trans[0];
		if (!isdigit(temp) && temp != '(' && temp != ')')//如果是运算符
		{
			if (m_S2.empty() || m_S2.top() == ")")
			{
				m_S2.push(trans);//如果栈2空或者栈	顶为右括号，直接压入
			}

			else//否则需要与栈顶元素比较优先级
			{
				compare(temp, m_S2.top(), trans);
			}
		}

		else if (temp == '(')/*如果是左括号，依次弹出栈1顶的运算符，并压入栈2，
							 直到遇到右括号为止，此时将这对括号舍弃*/
		{
			while (m_S2.top() != ")")
			{
				m_S1.push(m_S2.top());
				m_S2.pop();
			};
			m_S2.pop();
		}

		else if (temp == ')')//如果是右括号，直接压入栈2中，
		{
			m_S2.push(trans);
		}

		else//数字存进另一个栈
		{
			m_S1.push(trans);
		}
		expression[i] = "";
	}

	while (!m_S1.empty())/*将栈1剩余的运算符依次弹出并压入栈2，栈2中即中缀
						 表达式对应的前缀表达式倒叙*/
	{
		m_S2.push(m_S1.top());
		m_S1.pop();
	}
	string expression1[101];
	for (i = 0; !m_S2.empty(); i++)//将栈中倒序的表达式存入string中，接下来开始计算。
	{
		expression1[i] += m_S2.top();
		m_S2.pop();
	}
	int j = i;
	for (i = 0; i < j; i++)//从右至左扫描表达式
	{
		if (isdigit(expression1[i][0]))//遇到数字
		{
			stringstream stream(expression1[i]);
			stream >> num;
			m_S3.push(num);//压入栈中
			expression1[i] = "";
		}
		else//遇到运算符
		{
			double temp1, temp2, temp3;
			temp1 = m_S3.top(); m_S3.pop();
			temp2 = m_S3.top(); m_S3.pop();
			temp3 = cal(temp1, temp2, expression1[i][0]);//取出栈顶两个数字进行计算后压回栈中
			expression1[i] = "";
			m_S3.push(temp3);
		}
	}
	return m_S3.top();//最后栈顶的数字就是答案
	m_S3.pop();
}