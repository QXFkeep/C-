#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		_image = image;
		_real = real;
	}

	bool operator>(const Complex& d)      //大于
	{
		if (this->_real > d._real)
		{
			return true;
		}
		else if (this->_real == d._real)
		{
			if (this->_image > d._image)
			{
				return true;
			}
		}
		return false;
	}

	bool operator>=(const Complex& d)       //大于等于
	{
		return !(*this < d);
	}
	bool operator<(const Complex& d)       //小于
	{
		return !(*this == d || *this>d);
	}
	bool operator<=(const Complex& d)      //小于等于
	{
		return !(*this > d);
	}
	bool operator==(const Complex& d)       //相等
	{
		if (this->_real == d._real && this->_image == d._image)
		{
			return true;
		}
		return false;
	}

	Complex operator+(const Complex& d)    //加
	{
		Complex tmp;
		tmp._real = this->_real + d._real;
		tmp._image = this->_image + d._image;
		return tmp;
	}

	Complex& operator+=(const Complex& d)   //加等
	{
		this->_real += d._real;
		this->_image += d._image;
		return *this;
	}

	Complex operator-(const Complex& d)    //减
	{
		Complex tmp;
		tmp._real = this->_real - d._real;
		tmp._image = this->_image - d._image;
		return tmp;
	}
	Complex operator-=(const Complex& d)   //减等
	{
		this->_real -= d._real;
		this->_image -= d._image;
		return *this;
	}

	// c1=a+bi，c2=c+di   (ac－bd)+(bc+ad)i
	Complex operator*(Complex d)
	{
		Complex tmp;
		tmp._real = this->_real * d._real - this->_image * d._image;
		tmp._image = this->_image * d._real + this->_real * d._image;
		return tmp;
	}

	//c1=a+bi，c2=c+di  (a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
	Complex operator/(Complex d)
	{
		Complex tmp;
		tmp._real = (this->_real*d._real + this->_image*d._image) / (d._real*d._real
			+ d._image*d._image);
		tmp._image = (this->_image*d._real - this->_real*d._image) / (d._real*d._real
			+ d._image*d._image);
		return tmp;
	}

	Complex operator--()     //前置--
	{
		this->_real--;
		this->_image--;
		return *this;
	}

	Complex operator--(int)   //后置--
	{
		Complex tmp;
		tmp._real = this->_real;
		tmp._image = this->_image;
		this->_real--;
		this->_image--;
		return tmp;
	}

	Complex operator++()    //前置++
	{
		this->_real++;
		this->_image++;
		return *this;
	}
	Complex operator++(int) //后置++
	{
		Complex ret(*this);
		ret._real = this->_real;
		ret._image = this->_image;

		this->_real++;
		this->_image++;

		return ret;
	}

	void Display()         //打印
	{
		cout << "real=" << _real << "  " << "image=" << _image << endl;
	}

private:
	double _real;
	double _image;
};


void Test()
{
	Complex c1(1.0, 1.0);
	Complex c2(2.0, 2.0);
	cout << "c1的值为：";
	c1.Display();
	cout << "c2的值为：";
	c2.Display();

	cout << "    相加" << endl;
	Complex ret = c1 + c2;
	cout << "c1+c2的值为：";
	ret.Display();

	cout << "    后置++" << endl;
	cout << "c1的值为：";
	c1.Display();
	ret = c1++;
	cout << "c1后置++之后的值为：";
	ret.Display();

	cout << "    前置++" << endl;
	cout << "c1的值为：";
	c1.Display();
	ret = ++c1;
	cout << "c1前置++之后的值为：";
	ret.Display();

}

void Test1()
{
	Complex c1(5.0, 2.0);
	Complex c2(4.0, 4.0);
	cout << "c1的值为：";
	c1.Display();
	cout << "c2的值为：";
	c2.Display();

	cout << "    复数相乘" << endl;
	Complex ret = c1*c2;
	cout << "c1*c2相乘的结果为：";
	ret.Display();

	cout << "    复数相除" << endl;
	ret = c1 / c2;
	cout << "c1 / c2相乘的结果为：";
	ret.Display();

	if (c1 > c2)
	{
		cout << " c1>c2 的结果为：true" << endl;
	}
	else
	{
		cout << " c1 > c2 的结果为：false" << endl;
	}

}

void main()
{
	Test();
	Test1();
}