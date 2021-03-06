#include<string.h>
#include<iostream>
using namespace std;

class Student //声明Student类
{
public:
	Student(int n, char *nam, char s) //定义构造函数
	{
		num = n;
		strcpy_s(name, nam);
		sex = s;
		cout << "构造函数" << endl; //输出有关信息
	}
	~Student() //定义析构函数
	{
		cout << "析构函数" << endl;  //输出有关信息
	}
	void display() //定义成员函数
	{
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		cout << "sex: " << sex << endl << endl;
	}
private:
	int num;
	char name[10];
	char sex;
};

int main()
{
	Student stud1(10010, "Wang_li", 'f');     //建立对象stud1
	stud1.display();                            //输出学生1的数据
	Student stud2(10011, "Zhang_fun", 'm');     //定义对象stud2
	stud2.display();                            //输出学生2的数据
	return 0;
}