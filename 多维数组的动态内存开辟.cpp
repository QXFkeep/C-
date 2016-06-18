#include<iostream>
#include<cassert>
#include<iomanip>
using namespace std;

#define Type int

#define ROW 5
#define COL 5
#define Z   5
typedef Type(*Ar)[COL][ROW];

Ar _New()
{
	Ar p = new Type[Z][ROW][COL];
	return p;
}

void _Assign(Ar p)
{
	for (int k = 0; k < Z; ++k)
	{
		for (int j = 0; j < COL; ++j)
		{
			for (int i = 0; i < ROW; ++i)
			{
				p[k][i][j] = i + j + k;
			}

		}
	}	
}

void _Print(Ar p)
{
	for (int k = 0; k < Z; ++k)
	{
		for (int j = 0; j < COL; ++j)
		{
			for (int i = 0; i < ROW; ++i)
			{
				cout << setw(2)<<p[k][i][j] << " ";
			}
		}
		cout << endl;
	}
}

void _Delete(Ar p)
{
	delete []p;
}

void main()
{
	Ar p = _New();
	_Assign(p);
	_Print(p);
	_Delete(p);
}




//#define Type int
//
//#define ROW 5
//#define COL 5
//typedef Type(*Ar)[COL];
//
//Ar _New()
//{
//	Ar p = new Type[ROW][COL];
//	return p;
//}
//
//void _Assign(Ar p)
//{
//	for (int i = 0; i < ROW; ++i)
//	{
//		for (int j = 0; j < COL; ++j)
//		{
//			p[i][j] = i + j;
//		}
//	}	
//}
//
//void _Print(Ar p)
//{
//	for (int i = 0; i < ROW; ++i)
//	{
//		for (int j = 0; j < COL; ++j)
//		{
//			cout << p[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void _Delete(Ar p)
//{
//	delete []p;
//}
//
//void main()
//{
//	Ar p = _New();
//	_Assign(p);
//	_Print(p);
//	_Delete(p);
//}

//#define Type int
//
//#define ROW 5
//#define COL 5
//Type** _Malloc(int row, int col)
//{
//	Type **p = (Type**)malloc(sizeof(Type*)* row);
//	assert(p != NULL);
//	for (int i = 0; i < row; ++i)
//	{
//		p[i] = (Type*)malloc(sizeof(Type*)* col);
//		assert(p[i] != NULL);
//	}
//	return p;
//}
//
//void _Assign(Type **p, int row, int col)
//{
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			p[i][j] = i + j;
//		}
//	}
//}
//
//void _Print(Type **p, int row, int col)
//{
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			cout << p[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void _Delete(Type **p, int row)
//{
//	for (int i = 0; i < row; ++i)
//	{
//		delete []p[i];
//	}
//	delete[]p;
//}
//
//void main()
//{
//	Type **p = _Malloc(ROW, COL);
//	_Assign(p, ROW, COL);
//	_Print(p, ROW, COL);
//	_Delete(p, ROW);
//}