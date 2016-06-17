#include<iostream>
using namespace std;


//const修饰成员函数
//在成员函数后面加const，const修饰this指针所指向的对象，也就是保证调用这个const成员函数的对象在函数内不被改变。

//class Date
//{
//public:
//	void Display()
//	{
//		cout << "Display ()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//
//	void Display() const
//	{
//		cout << "Display () const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//
//void Test()
//{
//	Date d1;   //d1 用编译器生成的默认构造函数初始化的“const”自动数据产生不可靠的结果
//	d1.Display();
//
//	const Date d2;   //  void Display() const
//	d2.Display();
//}
//void main()
//{
//	Test();
//}



// 取地址运算符（这两个默认成员函数一般不用重新定义）

//

//友元类：
//整个类可以是另一个类的友元。友元类的每个成员函数都是另一个类的友元函数，都可访问另一个类中的保护或私有数据成员。
class Time
{
	// Date是Time 的友元，所以 Date可以访问Time的所有成员。
	friend class Date;
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	void Display()
	{
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;

		// 定义为友元类后，可以访问Time类对象的所有成员
		cout << "hour:" << _t._hour << endl;
		cout << "minute:" << _t._minute << endl;
		cout << "second:" << _t._second << endl << endl;
	}

private:
	int _year;     // 年
	int _month;    // 月
	int _day;      // 日

	Time _t;
};

void Test()
{
	Date d1;
	d1.Display();
}

void main()
{
	Test();
}