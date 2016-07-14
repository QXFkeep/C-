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
//	StringValue *value;//���е����ö��������Ψһһ��value��value����ʵ�ʴ洢data�����ô���  
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
//String::String(const String &rhs) {//Ҫ�����ü�1  
//	value = rhs.value;
//	value->refCount++;//����ָ��ͬһ��data�Ķ�������ü�1  
//}
//
//String &String::operator =(const String &rhs) {
//	if (value == rhs.value)//ע�⣬����this == &rhs  
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
//rcptr.hpp���򵥵�����ָ�룬����ָ���м������ܵĶ���ֵ����
#ifndef RCPTR_HPP
#define RCPTR_HPP
template<typename T>
class RCPtr{ //T����Ϊֵ�࣬��T����̳���RCObject
private:
	T* pointee; //��ָ��
	void init(){
		if (pointee == 0)
			return;
		//���ֵ���󲻿ɹ���
		if (pointee->isShareable() == false)
			pointee = new T(*pointee); //��ֻ�ܶ������п��������ܹ�����
		pointee->addReference(); //������һ���µ������󣨼�����˱�����ָ���������������
		//���ֵ����������ü���Ҫ��1
	}
public:
	RCPtr(T* realPtr = 0) :pointee(realPtr){ //����ָ��Ĺ���
		//����һ������ָ�룬˵������һ��ֵ����
		//���ü������1
		init();
	}
	RCPtr(RCPtr const& rhs) :pointee(rhs.pointee){ //����ָ��Ŀ���
		init();
	}
	RCPtr& operator=(RCPtr const& rhs){ //����ָ��ĸ�ֵ
		if (pointee == rhs.pointee)
			return *this; //���Ҹ�ֵ���
		T* oldPointee = pointee; //����ԭ����ָ��
		pointee = rhs.pointee; //ʵ�и�ֵ��ָ�����µ�ֵ����
		init(); //���ü�����1�����ֵ�����ܹ�����Ҫ���п���
		if (oldPointee) //ԭ��ָ���ֵ��������ü�����1��������0�������ٶ���
			oldPointee->removeReference();
		return *this;
	}
	~RCPtr(){
		if (pointee) //ֵ�������ü�����1��������0�������ٶ���
			pointee->removeReference();
	}
	T* operator->() const{
		return pointee; //������ָ��
	}
	T& operator*() const{
		return *pointee; //����ֵ����
	}
};
#endif

//string.hpp���ַ����࣬���ַ�����������ݽ��������ü�������ʹ����ַ���
//������ͬһ���ַ���ֵ
#ifndef STRING_HPP
#define STRING_HPP
#include <iostream>
#include <cstring>
//#include "rcobject.hpp"
//#include "rcptr.hpp"
class String{
private:
	//��ʾ�ַ������ݵ���Ƕ�࣬ʵ�������ü�������
	//���ֵ��������ڶ��ϴ���
	struct StringValue : public RCObject{
		char *data;
		void init(char const* initValue){
			data = new char[strlen(initValue) + 1];
			strcpy(data, initValue); //���ַ������п���
		}
		StringValue(char const *initValue){ //ֵ����Ĺ���
			init(initValue);
		}
		StringValue(StringValue const& rhs){ //ֵ����Ŀ���
			init(rhs.data);
		}
		~StringValue(){
			delete[] data;
		}
	};
	RCPtr<StringValue> value; //String��������ݣ�������ָ��RCPtr��װ��
	friend std::ostream& operator<<(std::ostream&, String const&);
public:
	String(char const* initValue = "")
		:value(new StringValue(initValue)){
	}
	char const& operator[](int index) const{ //const�汾��ֻ�����Ƕ�����
		return value->data[index];
	}
	char& operator[](int index){ //��const�汾�������Ƕ�Ҳ������д
		//�����Ҫ���дʱ����
		if (value->isShared()){ //����Ѿ���������
			value = new StringValue(value->data); //����뿽��һ�ݳ�������д����
		}
		value->markUnshareable(); //���Ϊ���ɹ���
		return value->data[index];
	}
};
inline std::ostream& operator<<(std::ostream& os, String const& str){
	os << (str.value)->data;
	return os;
}
#endif

//stringtest.cpp����String�Ĳ���
#include <iostream>
//#include "string.hpp"
using namespace std;
int main(){
	String s1("abcd");
	cout << s1 << endl;
	String s2("efgh");
	s2 = s1; //s2��s1����"abcd"
	cout << s2 << endl;
	const String s3(s1); //s1,s2,s3����abcd"
	cout << s3 << endl;
	cout << s3[2] << endl; //������������const�汾��opeator[]��
	//������п���
	cout << s2[2] << endl; //������������non-const�汾��opeator[]��
	//����п���
	s2[2] = 'x'; //д����������non-const�汾��opeator[]��
	//����п�������дʱ����
	cout << s2 << endl; //����޸ĺ��ֵ
	return 0;
}