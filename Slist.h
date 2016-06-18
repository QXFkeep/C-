#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int DataType;

struct SlistNode
{
	SlistNode(const DataType& x)
	:_data(x)
	, _next(NULL)
	{}

	DataType _data;
	SlistNode* _next;
};

class Slist
{
public:
	Slist()
		:_head(NULL)
		, _tail(NULL)
	{}
	~Slist()
	{
		Clear();
	}

	Slist(const Slist& s)
		:_head(NULL)
		, _tail(NULL)
	{
		SlistNode* begin = s._head;
		while (begin)
		{
			PushBack(begin->_data);
			begin = begin->_next;
		}
	}

public:
	void Print()
	{
		SlistNode* begin = _head;
		while (begin)
		{
			cout << begin->_data << "->";
			begin = begin->_next;
		}
		cout << "NULL" << endl;
	}

	void PushBack(const DataType& x)
	{
		if (_head == NULL)
		{
			_head = new SlistNode(x);
			_tail = _head;
		}
		else
		{
			_tail->_next = new SlistNode(x);
			_tail = _tail->_next;
		}
	}

	void PopBack()
	{
		if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			SlistNode* tailprv = _head;
			while (tailprv->_next != _tail)
			{
				tailprv = tailprv->_next;
			}
			tailprv->_next = NULL;
			delete _tail;
			_tail = tailprv;
		}
	}

	SlistNode* Find(const DataType& x)
	{
		SlistNode* begin = _head;
		while (begin)
		{
			if (begin->_data == x)
			{
				return begin;
			}
			begin = begin->_next;
		}
		return NULL;
	}

	void Insert(SlistNode* pos, const DataType& x)
	{
		assert(pos);
		SlistNode* tmp = new SlistNode(x);
		if (pos == _tail)
		{
			_tail->_next = tmp;
			_tail = tmp;
		}
		else
		{
			SlistNode* next = pos->_next;
			pos->_next = tmp;
			tmp->_next = next;
		}
	}

	void Erase(SlistNode* pos)
	{
		assert(pos);

		while (_head != pos)
		{
			_head = _head->_next;
		}
		_head = pos->_next;
		delete pos;
	}

	void Swap(Slist& s)
	{
		swap(s._head, _head);
		swap(s._tail, _tail);
	}

	void Clear()
	{
		SlistNode* begin = _head;
		while (begin)
		{
			SlistNode* del = begin;
			begin = begin->_next;
			delete del;
		}
		_head = _tail = NULL;
	}


	void Del_Max(Slist& s)   //ɾ�����ֵ
	{
		
		SlistNode* p;
		SlistNode* max;
		p = s._head;
		max = s._head;
		int n = p->_data;

		while (p->_next != NULL)
		{
			p = p->_next;
			if (p->_data > n)
			{
				max = p;
				n = p->_data;
			}
		}

		if (NULL == max->_next)
		{
			PopBack();
		}
		else
		{
			n = max->_next->_data;
			max->_data = n;
			max->_next = max->_next->_next;
		}
	}

	void SlistConcat(Slist& s1, Slist& s2)
	{
		SlistNode * begin = s1._head;
		while (begin)
		{
			this->PushBack(begin->_data);
			begin = begin->_next;
		}
		begin = s2._head;
		while (begin)
		{
			PushBack(begin->_data);
			begin = begin->_next;
		}
	}


private:
	SlistNode* _head;
	SlistNode* _tail;
};


void Test1()
{
	Slist s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.Print();

	s1.PushBack(99);
	cout << "β���:> " << endl;
	s1.Print();

	SlistNode* ret;
	ret = s1.Find(3);          //���ҵ�ĳ������ֵ�Ľ�㣬���ڸýڵ���������ֵ��
	s1.Insert(ret, 100000);
	cout << "��ֵΪ3�Ľ������100֮��:> " << endl;
	s1.Print();

	ret = s1.Find(1);      
	s1.Insert(ret, 1000);
	cout << "��ֵΪ1�Ľ������1000֮��:> " << endl;
	s1.Print();

	ret = s1.Find(1);
	s1.Erase(ret);
	cout << "ɾ��ֵΪ1�Ľ��֮��:> " << endl;
	s1.Print();

	s1.Del_Max(s1);
	cout << "ɾ�����ֵ�Ľ��֮��:> " << endl;
	s1.Print();

}

void Test2()
{
	Slist s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.Print();

	Slist s2;
	s2.PushBack(5);
	s2.PushBack(6);
	s2.PushBack(7);
	s2.PushBack(8);
	s2.Print();

	Slist s;
	s.SlistConcat(s1, s2);
	s.Print();
}