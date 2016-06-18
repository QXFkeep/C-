#include<iostream>
using namespace std;

//纯虚函数
// virtual 返回类型 函数名 (参数表) = 0;
class A
{
public:
	virtual void Eat() = 0;    //纯虚函数，父类的方法永远不会被调用到，没有必要具体实现
	virtual void Sleep() = 0;  //"=0"表明不定义该函数，函数声明是为派生类保留的一个位置， "=0"本质上是将指向函数体的指针定为NULL.  如 int *p = NULL,  只是为了占位置
};

class P : public A
{
public:
	virtual void Eat()
	{
		cout << "P Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "P Sleep()" << endl;
	}
};

class Dog : public A
{
public:
	virtual void Eat()
	{
		cout << "Dog Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "Dog Sleep()" << endl;
	}
};


void fun(A *pa)
{
	pa->Eat();     //会多态的调用子类方法，不会调用父类方法
	pa->Sleep();
}


void main()
{
	P p;
	Dog dog;

	fun(&p);
	fun(&dog);
}