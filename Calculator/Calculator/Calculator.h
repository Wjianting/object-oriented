#include<string> 
#include<queue>
#include<stack>
using namespace std;


class Scan
{
public:
	queue<string>ToStringQueue(string input);
private:
	queue<string>m_quQueue;
	int length = 0;//lengh�������ֵĳ����Ƿ񳬱�. 
	string trans = "";//trans��char��ת��Ϊstring��. 
};


class Print :public Scan
{
public:
	void Print::ToOutput1(double answer, string exp);
	void Print::ToOutput2(double answer);
};

class Calculation :private Scan
{
public:
	int ToCalculate(queue<string>queue);
	int priority(char x);
	void Calculation::compare(char m, string n, string q);
private:
	stack<string>m_S1;
	stack<string>m_S2;
	stack<double>m_S3;
};