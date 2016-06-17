#include<iostream>
#include<string.h>
#include<assert.h>
#include<windows.h>
using namespace std;


//class String
//{
//public:
//	friend ostream& operator<<(ostream& os, const String& s);
//
//	String(const char* str = "")
//		:_str ( new char [strlen(str) + 1])
//	{
//		int len = strlen(str);
//		_capacity = len + 1;
//		_size = len;
//		_str = new char[_capacity];
//		strcpy_s(_str, strlen(str)+1, str);
//	}
//
//	void _Swap(String& s)
//	{
//		swap(_str, s._str);
//		swap(_size, s._size);
//		swap(_capacity, s._capacity);
//	}
//
//	String(const String& s)
//		:_str(NULL)
//	{
//		String tmp(s._str);
//		this->_Swap(tmp);
//	}
//
//	//String& operator=(const String& s)
//	//{
//	//	if (this != &s)
//	//	{
//	//		String tmp(s._str);
//	//		//swap(_str, tmp._str);
//	//		this->_Swap(tmp);
//	//	}
//	//	return *this;
//	//}
//
//	String& operator=(String s)
//	{
//		//swap(_str, s._str);
//		this->_Swap(s);
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[]_str;
//			_str = NULL;
//		}
//	}
//
//public:
//	bool operator>(const String& s)
//	{
//		const char* str1 = _str;
//		const char* str2 = s._str;
//		while (*str1 && *str2)
//		{
//			if (*str1 > *str2)
//			{
//				return true;
//			}
//			else if (*str1 < *str2)
//			{
//				return false;
//			}
//			else
//			{
//				++str1;
//				++str2;
//			}
//		}
//		if (*str1)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator>=(const String& s)
//	{
//		return *this > s || *this == s;
//	}
//	bool operator<(const String& s)
//	{
//		return !((*this > s) || (*this == s));
//	}
//	bool operator<=(const String& s)
//	{
//		return *this < s || *this == s;
//	}
//	bool operator==(const String& s)
//	{
//		const char* str1 = _str;
//		const char* str2 = s._str;
//		while (*str1 && *str2)
//		{
//			if (*str1 == *str2)
//			{
//				++str1;
//				++str2;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		if (*str1 || *str2)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//public:
//	void PushBack(char ch)
//	{
//		//_CheckCapacity(_size + 2);
//		//_str[_size++] = ch;
//		//_str[_size] = '\0';
//
//		Insert(_size, ch);
//	}
//	
//	void Insert(int pos, char ch)
//	{
//		assert(pos <= _size);
//
//		_CheckCapacity(_size + 2);
//
//		int end = _size;
//		while (end >= pos)
//		{
//			_str[end + 1] = _str[end];
//			--end;
//		}
//		_str[pos] = ch;
//		++_size;
//	}
//
//	void Insert(int pos, const char* str)
//	{
//		size_t strSize = strlen(str);
//		_CheckCapacity(_size + 1 + strSize);
//
//		int end = _size;
//		while (end >= pos)
//		{
//			_str[end + strSize] = _str[end];
//			--end;
//		}
//		while (*str)
//		{
//			_str[pos++] = *str++;
//		}
//		_size += strSize;
//	}
//
//	char& operator[](size_t index)
//	{
//		return _str[index];
//	}
//
//
//	int Find(char ch)
//	{
//		//char* str = _str;
//		//while (*str)
//		//{
//		//	if (*str == ch)
//		//	{
//		//		return (str - _str - 1);
//		//	}
//		//	++str;
//		//}
//		//return -1;
//		char* str = _str;
//		int begin = 0;
//		while (str[begin])
//		{
//			if (str[begin] == ch)
//			{
//				return begin;
//			}
//			++begin;
//		}
//		return -1;
//	}
//
//	int Find(const char* str)
//	{
//		assert(*str);
//		const char* src = _str;
//		const char* sub = str;
//
//		int srcLen = _size;
//		int subLen = strlen(sub);
//
//		int srcIndex = 0;
//		while (srcIndex <= srcLen - subLen)
//		{
//			int i = srcIndex;
//			int j = 0;
//			while (i < srcLen && j < subLen && src[i] == sub[j])
//			{
//				++i;
//				++j;
//			}
//			if (j == subLen)
//			{
//				return srcIndex;
//			}
//			++srcIndex;
//		}
//		return -1;
//	}
//
//
//	void Erase(size_t pos)
//	{
//		assert(pos < _size);
//		char* str = _str;
//		for (size_t i = pos; i < _size; ++i)
//		{
//			str[i] = str[i + 1];
//		}
//		 _size--;
//		 _capacity--;
//	}
//
//	void Erase(size_t pos, size_t n)
//	{
//		assert((pos < _size) && (pos + n < _size));
//		char* str = _str;
//		for (size_t i = pos; i < _size; ++i)   
//		{
//			str[i] = str[i + n];
//		}
//		_size -= n;
//		_capacity -= n;
//	}
//
//private:
//	void _CheckCapacity(size_t size)
//	{
//		if (size > _capacity)
//		{
//			int newCapaacity = size > 2 * _capacity ? size : 2 * _capacity;
//
//			_str = (char*)realloc(_str, newCapaacity);
//			_capacity = newCapaacity;
//		}
//	}
//
//private:
//	char* _str;
//
//	size_t _size;
//	size_t _capacity;
//};
//
//ostream& operator<<(ostream& os, const String& s)
//{
//	os << s._str << endl;
//	return os;
//}
//
//
//void Test1()
//{
//	String s1("hello world");
//	String s2("change world");
//
//	cout << (s1 > s2) << endl;
//}
//void Test2()
//{
//	String s1("a");
//	s1.Insert(1, "xxxxx");
//	cout << s1 ;
//
//	String s2("abcdefg");
//	s2.Insert(2,"g");
//	cout << s2 ;
//}
//
//void Test3()
//{
//	String s2("abcdefg");
//	cout<<"该字符的下标为:>"<<s2.Find('d')<<endl;
//}
//
//void Test4()
//{
//	String s4("abcdefg");
//	cout << s4;
//	cout << s4.Find("bc")<<endl;
//	cout << s4.Find("gh") << endl;
//	s4.Erase(6);
//	cout << s4;
//
//	s4.Erase(2, 2);
//	cout << s4;
//}
//
//void Test5()
//{
//	int begin = GetTickCount();  //调用系统函数 统计毫秒
//	String s5("11111111111111111111111111");
//	for (int i = 0; i < 1000000; ++i)
//	{
//		String s6(s5);
//	}
//	int end = GetTickCount();
//	cout << end - begin << endl;
//}
//void main()
//{
//	//Test1();
//	//Test2();
//	//Test3();
//	Test4();
//	Test5();
//}


//namespace COW
//{
//	class String
//	{
//	public:
//		String(const char* str)
//			:_str(new char[strlen(str) + 1])
//			,_pCount(new int(1))
//		{
//			strcpy_s(_str, strlen(str) + 1, str);
//		}
//
//		String(const String& s)
//			: _str(s._str)
//			, _pCount(s._pCount)
//		{
//			//*((int*)_str - 1) += 1;
//			++(*_pCount);
//		}
//
//		String& operator=(const String& s)
//		{
//			if (_str != s._str)
//			{
//              //释放原对象
//				if (--(*_pCount) == 0)
//				{
//					delete _pCount;
//					delete[] _str;
//				}
//               //浅拷贝并增加引用计数
//				_str = s._str;
//				_pCount = s._pCount;
//				++(*_pCount);
//			}
//			return *this;
//		}
//
//		~String()
//		{
//			if (--(*_pCount) == 0)
//			{
//				cout << "delete[] _str" << endl;
//				delete _pCount;
//				delete[] _str;
//				
//			}
//		}
//	private:
//		char* _str;
//		int* _pCount;
//	};
//
//	void Test()
//	{
//		String s1("11111111111111111");
//		String s2(s1);
//		String s3(s2);
//
//
//		String s4("22222222222222222");
//		String s5(s4);
//
//		s1 = s3;
//	}
//}
//
//int main()
//{
//	COW::Test();
//	return 0;
//}


namespace COW
{
	class String
	{
	public:
		String(const char* str)
			:_str(new char[strlen(str) + 5])
		{
			//(*(int*)_str) = 1;
			_str += 4;
			strcpy_s(_str, strlen(str) + 1, str);
			_GetRefCount(_str) = 1;
		}

		String(const String& s)
			:_str(s._str)
		{
			//*((int*)_str -1) += 1;
			++_GetRefCount(_str);
		}

		String& operator=(const String& s)
		{
			if (_str != s._str)
			{
				_Release();
				_str = s._str;
				//*((int*)_str - 1) += 1;
				++_GetRefCount(_str);
			}
			return *this;
		}

		~String()
		{
			_Release();
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}
	private:
		int& _GetRefCount(char* _ptr)
		{
			return *(int*)(_ptr - 4);
		}

		void _Release()
		{
			//if (--(*((int*)_str - 1)) == 0)
			if (--_GetRefCount(_str) == 0)
			{
				delete[] (_str - 4);
			}
		}
	private:
		char* _str;
	};



	void Test()
	{
		String s1("11111111111111111");
		String s2(s1);
		cout << s1[0] << endl;
	//	cout << s1[1] = 'x' << endl;
		String s3("22222222222222222");
		s1 = s3;
	}
}

void main()
{
	COW::Test();
}