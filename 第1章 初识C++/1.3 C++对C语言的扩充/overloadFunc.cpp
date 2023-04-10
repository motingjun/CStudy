#include<iostream>

using namespace std;

void add(int x, int y)
{
	cout << "int: " << x + y << endl;
}

void add(double x)
{
	cout << "double: " << 10 + x << endl;
}

double add(double x, double y)
{
	return x + y;
}

int main()
{
	add(10.2);	//一个double类型参数
	add(1, 3);	//两个int类型参数
	return 0;
}


/*
结果:
double: 20.2
int: 4
*/


/*
所谓函数重载（overload），就是在同一个作用域内函数名相同但参数个数或者参数类型不同的函数。

在编写程序时，要杜绝重载的函数有默认参数，从而避免调用二义性的发生。
如:
int add(int x, int y = 1); 
void add(int x);
*/