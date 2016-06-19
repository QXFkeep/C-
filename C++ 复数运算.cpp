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

	bool operator>(const Complex& d)      //����
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

	bool operator>=(const Complex& d)       //���ڵ���
	{
		return !(*this < d);
	}
	bool operator<(const Complex& d)       //С��
	{
		return !(*this == d || *this>d);
	}
	bool operator<=(const Complex& d)      //С�ڵ���
	{
		return !(*this > d);
	}
	bool operator==(const Complex& d)       //���
	{
		if (this->_real == d._real && this->_image == d._image)
		{
			return true;
		}
		return false;
	}

	Complex operator+(const Complex& d)    //��
	{
		Complex tmp;
		tmp._real = this->_real + d._real;
		tmp._image = this->_image + d._image;
		return tmp;
	}

	Complex& operator+=(const Complex& d)   //�ӵ�
	{
		this->_real += d._real;
		this->_image += d._image;
		return *this;
	}

	Complex operator-(const Complex& d)    //��
	{
		Complex tmp;
		tmp._real = this->_real - d._real;
		tmp._image = this->_image - d._image;
		return tmp;
	}
	Complex operator-=(const Complex& d)   //����
	{
		this->_real -= d._real;
		this->_image -= d._image;
		return *this;
	}

	// c1=a+bi��c2=c+di   (ac��bd)+(bc+ad)i
	Complex operator*(Complex d)
	{
		Complex tmp;
		tmp._real = this->_real * d._real - this->_image * d._image;
		tmp._image = this->_image * d._real + this->_real * d._image;
		return tmp;
	}

	//c1=a+bi��c2=c+di  (a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
	Complex operator/(Complex d)
	{
		Complex tmp;
		tmp._real = (this->_real*d._real + this->_image*d._image) / (d._real*d._real
			+ d._image*d._image);
		tmp._image = (this->_image*d._real - this->_real*d._image) / (d._real*d._real
			+ d._image*d._image);
		return tmp;
	}

	Complex operator--()     //ǰ��--
	{
		this->_real--;
		this->_image--;
		return *this;
	}

	Complex operator--(int)   //����--
	{
		Complex tmp;
		tmp._real = this->_real;
		tmp._image = this->_image;
		this->_real--;
		this->_image--;
		return tmp;
	}

	Complex operator++()    //ǰ��++
	{
		this->_real++;
		this->_image++;
		return *this;
	}
	Complex operator++(int) //����++
	{
		Complex ret(*this);
		ret._real = this->_real;
		ret._image = this->_image;

		this->_real++;
		this->_image++;

		return ret;
	}

	void Display()         //��ӡ
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
	cout << "c1��ֵΪ��";
	c1.Display();
	cout << "c2��ֵΪ��";
	c2.Display();

	cout << "    ���" << endl;
	Complex ret = c1 + c2;
	cout << "c1+c2��ֵΪ��";
	ret.Display();

	cout << "    ����++" << endl;
	cout << "c1��ֵΪ��";
	c1.Display();
	ret = c1++;
	cout << "c1����++֮���ֵΪ��";
	ret.Display();

	cout << "    ǰ��++" << endl;
	cout << "c1��ֵΪ��";
	c1.Display();
	ret = ++c1;
	cout << "c1ǰ��++֮���ֵΪ��";
	ret.Display();

}

void Test1()
{
	Complex c1(5.0, 2.0);
	Complex c2(4.0, 4.0);
	cout << "c1��ֵΪ��";
	c1.Display();
	cout << "c2��ֵΪ��";
	c2.Display();

	cout << "    �������" << endl;
	Complex ret = c1*c2;
	cout << "c1*c2��˵Ľ��Ϊ��";
	ret.Display();

	cout << "    �������" << endl;
	ret = c1 / c2;
	cout << "c1 / c2��˵Ľ��Ϊ��";
	ret.Display();

	if (c1 > c2)
	{
		cout << " c1>c2 �Ľ��Ϊ��true" << endl;
	}
	else
	{
		cout << " c1 > c2 �Ľ��Ϊ��false" << endl;
	}

}

void main()
{
	Test();
	Test1();
}