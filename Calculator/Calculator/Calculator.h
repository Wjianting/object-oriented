#include<string> 
#include<queue>
using namespace std;


class Scan
{
public:
	queue<string>ToStringQueue(string input);
private:
	queue<string>m_quQueue;
	int    length = 0;//lengh�������ֵĳ����Ƿ񳬱�. 
	string trans = "";//trans��char��ת��Ϊstring��. 
};


class Print
{
public:
	void ToOutput(queue<string>queue);
};

