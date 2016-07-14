//#include <iostream>  
//#include <stdio.h>  
//
//using namespace std;
//
//class String {
//public:
//	String(const char *pdata);
//	String(const String &rhs);
//	String &operator = (const String &rhs);
//	~String();
//private:
//	class StringValue {
//	public:
//		int refCount;
//		char *data;
//		StringValue(const char *pdata);
//		~StringValue();
//	};
//
//	StringValue *value;//所有的引用对象均共享唯一一个value，value里面实际存储data和引用次数  
//};
//
//String::StringValue::StringValue(const char *pdata) :refCount(1) {
//	data = new char[strlen(pdata) + 1];
//	strcpy_s(data, strlen(pdata) + 1, pdata);
//}
//
//String::StringValue::~StringValue() {
//	delete[] data;
//}
//
//String::String(const char *pdata) :value(new StringValue(pdata))
//{}
//
//String::String(const String &rhs) {//要对引用加1  
//	value = rhs.value;
//	value->refCount++;//所有指向同一段data的对象的引用加1  
//}
//
//String &String::operator =(const String &rhs) {
//	if (value == rhs.value)//注意，不是this == &rhs  
//		return *this;
//	if (--value->refCount == 0)
//		delete value;
//
//	value = rhs.value;
//	++value->refCount;
//
//	return *this;
//}
//
//String::~String() {
//	if (--value->refCount == 0)
//		delete value;
//}
//
//void test() {
//	String ss("ssss");
//	String s1 = ss;
//	String s2("dddd");
//	s2 = ss;
//}
//
//int main() 
//{
//	test();
//}

//http://blog.csdn.net/zhoudaxia/article/details/4566914
//rcptr.hpp：简单的智能指针，用于指向有计数功能的对象（值对象）
#ifndef RCPTR_HPP
#define RCPTR_HPP
template<typename T>
class RCPtr{ //T必须为值类，即T必须继承自RCObject
private:
	T* pointee; //哑指针
	void init(){
		if (pointee == 0)
			return;
		//如果值对象不可共享
		if (pointee->isShareable() == false)
			pointee = new T(*pointee); //则只能对它进行拷贝，不能共享它
		pointee->addReference(); //现在有一个新的主对象（即组合了本智能指针的主对象）引用了
		//这个值对象，因此引用计数要加1
	}
public:
	RCPtr(T* realPtr = 0) :pointee(realPtr){ //智能指针的构造
		//产生一个智能指针，说明有了一个值对象
		//引用计数会加1
		init();
	}
	RCPtr(RCPtr const& rhs) :pointee(rhs.pointee){ //智能指针的拷贝
		init();
	}
	RCPtr& operator=(RCPtr const& rhs){ //智能指针的赋值
		if (pointee == rhs.pointee)
			return *this; //自我赋值情况
		T* oldPointee = pointee; //保存原来的指针
		pointee = rhs.pointee; //实行赋值，指向了新的值对象
		init(); //引用计数加1，如果值对象不能共享，则要进行拷贝
		if (oldPointee) //原来指向的值对象的引用计数减1，如果变成0，会销毁对象
			oldPointee->removeReference();
		return *this;
	}
	~RCPtr(){
		if (pointee) //值对象引用计数减1，如果变成0，则销毁对象
			pointee->removeReference();
	}
	T* operator->() const{
		return pointee; //返回哑指针
	}
	T& operator*() const{
		return *pointee; //返回值对象
	}
};
#endif

//string.hpp：字符串类，对字符串对象的内容进行了引用计数，可使多个字符串
//对象共享同一个字符串值
#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>
#include <cstring>
//#include "rcobject.hpp"
//#include "rcptr.hpp"
class String{
private:
	//表示字符串内容的内嵌类，实现了引用计数功能
	//这个值对象必须在堆上创建
	struct StringValue : public RCObject{
		char *data;
		void init(char const* initValue){
			data = new char[strlen(initValue) + 1];
			strcpy(data, initValue); //对字符串进行拷贝
		}
		StringValue(char const *initValue){ //值对象的构造
			init(initValue);
		}
		StringValue(StringValue const& rhs){ //值对象的拷贝
			init(rhs.data);
		}
		~StringValue(){
			delete[] data;
		}
	};
	RCPtr<StringValue> value; //String对象的内容，用智能指针RCPtr封装它
	friend std::ostream& operator<<(std::ostream&, String const&);
public:
	String(char const* initValue = "")
		:value(new StringValue(initValue)){
	}
	char const& operator[](int index) const{ //const版本：只可能是读操作
		return value->data[index];
	}
	char& operator[](int index){ //非const版本：可能是读也可能是写
		//因此需要完成写时拷贝
		if (value->isShared()){ //如果已经被共享了
			value = new StringValue(value->data); //则必须拷贝一份出来进行写操作
		}
		value->markUnshareable(); //标记为不可共享
		return value->data[index];
	}
};
inline std::ostream& operator<<(std::ostream& os, String const& str){
	os << (str.value)->data;
	return os;
}
#endif

//stringtest.cpp：对String的测试
#include <iostream>
//#include "string.hpp"
using namespace std;
int main(){
	String s1("abcd");
	cout << s1 << endl;
	String s2("efgh");
	s2 = s1; //s2和s1共享"abcd"
	cout << s2 << endl;
	const String s3(s1); //s1,s2,s3共享“abcd"
	cout << s3 << endl;
	cout << s3[2] << endl; //读操作，调用const版本的opeator[]，
	//不会进行拷贝
	cout << s2[2] << endl; //读操作，调用non-const版本的opeator[]，
	//会进行拷贝
	s2[2] = 'x'; //写操作，调用non-const版本的opeator[]，
	//会进行拷贝，即写时拷贝
	cout << s2 << endl; //输出修改后的值
	return 0;
}