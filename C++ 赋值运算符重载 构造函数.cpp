#include<iostream>
using namespace std;

//赋值运算符重载
//class Date
//{
//public:
//	Date()
//	{}
//
//	//拷贝构造函数
//	Date(const Date& d)
//		:_year(d._year)
//		,_month(d._month)
//		, _day(d._day)
//	{}
//	
//	//赋值操作符的重载
//	//operator=赋值函数需要一个Date&的返回值，并且其可以用void做返回值
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			this->_year = d._year;
//			this->_month = d._month;
//			this->_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void main()
//{
//	Date d1;
//	Date d2 = d1;  //调用构造函数
//
//	Date d3;
//	d3 = d1;       //调用赋值运算符的重载
//}

//深入探索构造函数
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//	Time(const Time& t)
//	{
//		cout << "Time(const Time& t)" << endl;
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//
//class Date
//{
//public:
//	/*
//	Date(int year, int month, int day, const Time& t)
//	{
//		cout << "Date()-非初始化列表" << endl;
//
//		_year = year;
//		_month = month;
//		_day = day;
//		_t = t;
//	}
//	*/
//
//	Date(int year, int month, int day, const Time& t)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		,_t(t)
//	{
//		cout << "Date()-初始化列表" << endl;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//void Test()
//{
//	Time t1;
//	Date d1(2015,11,29,t1);
//}
//
//void main()
//{
//	Test();
//}


class Date
{
public:
	Date(int x)    //成员变量按照声明顺序依次初始化，而非初始化列表出现的顺序
		:_day(x)    //按照private中的申明先初始化year，month，day
		,_month(_day) //所以在初始化_month时，_day还没有被初始化，所以为随机值!!!
		,_year(x)    
	{
		cout << "Date()" << endl;
	}
	void Display()
	{
		cout << "year:"<<_year<< endl;
		cout << "month:" << _month<< endl;
		cout << "day:" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1(1);
	d1.Display();
}

void main()
{
	Test();
}

