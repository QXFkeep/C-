#include<iostream>
using namespace std;

//���麯��
// virtual �������� ������ (������) = 0;
class A
{
public:
	virtual void Eat() = 0;    //���麯��������ķ�����Զ���ᱻ���õ���û�б�Ҫ����ʵ��
	virtual void Sleep() = 0;  //"=0"����������ú���������������Ϊ�����ౣ����һ��λ�ã� "=0"�������ǽ�ָ�������ָ�붨ΪNULL.  �� int *p = NULL,  ֻ��Ϊ��ռλ��
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
	pa->Eat();     //���̬�ĵ������෽����������ø��෽��
	pa->Sleep();
}


void main()
{
	P p;
	Dog dog;

	fun(&p);
	fun(&dog);
}