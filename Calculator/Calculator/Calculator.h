#include<string> 
#include<queue>
using namespace std;


class Scan
{
public:
	queue<string>ToStringQueue(string input);
private:
	queue<string>m_quQueue;
	int    length = 0;//lengh计算数字的长度是否超标. 
	string trans = "";//trans将char型转换为string型. 
};


class Print
{
public:
	void ToOutput(queue<string>queue);
};

