#include<iostream>
using namespace std;

//����Base�࣬һ��Ҫ��̳С���̳е�һ���������������Ĺ��캯�����������ฺ���죡
template<class T>
class Base
{
	friend T;
private:
	Base()
	{}
	~Base()
	{}
};

class Derive
{
public:
	Derive()
	{
		cout << "Creat Object Derive()" << endl;
	}
	~Derive()
	{}
};

class DB :virtual public Base<DB>, public Derive
{
public:
	DB()
	{}
	~DB()
	{}
};

class Child :public DB
{};

void main(int argc, char* argv[])
{
	DB d;
	//Child c;

}