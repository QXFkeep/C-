#include<iostream>
using namespace std;

//��ֵ���������
//class Date
//{
//public:
//	Date()
//	{}
//
//	//�������캯��
//	Date(const Date& d)
//		:_year(d._year)
//		,_month(d._month)
//		, _day(d._day)
//	{}
//	
//	//��ֵ������������
//	//operator=��ֵ������Ҫһ��Date&�ķ���ֵ�������������void������ֵ
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
//	Date d2 = d1;  //���ù��캯��
//
//	Date d3;
//	d3 = d1;       //���ø�ֵ�����������
//}

//����̽�����캯��
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
//		cout << "Date()-�ǳ�ʼ���б�" << endl;
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
//		cout << "Date()-��ʼ���б�" << endl;
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
	Date(int x)    //��Ա������������˳�����γ�ʼ�������ǳ�ʼ���б���ֵ�˳��
		:_day(x)    //����private�е������ȳ�ʼ��year��month��day
		,_month(_day) //�����ڳ�ʼ��_monthʱ��_day��û�б���ʼ��������Ϊ���ֵ!!!
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

