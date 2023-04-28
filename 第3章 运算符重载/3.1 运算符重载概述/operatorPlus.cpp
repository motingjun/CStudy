#include <iostream>

using namespace std;

class A
{
private:
	int _x;
	int _y;
public:
	A(int x=0, int y=0):_x(x),_y(y){}

	void show() const;
	A operator++();		//重载前置"++"
	A operator++(int);	//重载后置"++"	
};

void A::show() const
{
	cout<<"(_x,_y)="<<"("<<_x<<","<<_y<<")"<<endl;
}

A A::operator++()
{
	++_x;
	++_y;
	return *this;
}

A A::operator++(int)
{
	A a = *this;
	++(*this);		//调用已经实现的前置"++"
	return a;
}


int main(int argc, char const *argv[])
{
	A a1(1,2), a2(3,4);
	(a1++).show();
	(++a2).show();
	return 0;
}


/*
结果:
(_x,_y)=(1,2)
(_x,_y)=(4,5)
*/


/*
运算符重载一般有两种形式：重载为类的成员函数和重载为类的友元函数。
此示例为重载为类的成员函数
*/