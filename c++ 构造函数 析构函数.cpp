#include<string.h>
#include<iostream>
using namespace std;

class Student //����Student��
{
public:
	Student(int n, char *nam, char s) //���幹�캯��
	{
		num = n;
		strcpy_s(name, nam);
		sex = s;
		cout << "���캯��" << endl; //����й���Ϣ
	}
	~Student() //������������
	{
		cout << "��������" << endl;  //����й���Ϣ
	}
	void display() //�����Ա����
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
	Student stud1(10010, "Wang_li", 'f');     //��������stud1
	stud1.display();                            //���ѧ��1������
	Student stud2(10011, "Zhang_fun", 'm');     //�������stud2
	stud2.display();                            //���ѧ��2������
	return 0;
}