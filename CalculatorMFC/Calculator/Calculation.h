#include<string> 
#include<queue>
#include<stack>
using namespace std;

class Scan
{
public:
	string Open(char *in);
	queue<string>ToStringQueue(string input);
	Scan();
	~Scan();
private:
	queue<string>m_quQueue;
	int length = 0;
	string trans = "";
};

class Calculation:private Scan
{
public:
	double ToCalculate(queue<string>queue);
	int priority(char x);
	void Calculation::compare(char m, string n, string q);
	Calculation();
	~Calculation();
private:
	stack<string>m_S1;
	stack<string>m_S2;
	stack<double>m_S3;
};

