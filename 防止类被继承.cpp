#include<iostream>
using namespace std;

//调用Base类，一定要虚继承。虚继承的一个特征就是虚基类的构造函数由最终子类负责构造！
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