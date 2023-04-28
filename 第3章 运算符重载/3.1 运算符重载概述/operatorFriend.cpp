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
	friend A operator+(const A& a1, const A& a2);	//重载为类的友元函数
	friend A operator-(const A& a1, const A& a2);	//重载为类的友元函数
};

void A::show() const
{
	cout<<"(_x,_y)="<<"("<<_x<<","<<_y<<")"<<endl;
}

A operator+(const A& a1, const A& a2)
{
	return A(a1._x+a2._x, a1._y+a2._y);
}

A operator-(const A& a1, const A& a2)
{
	return A(a1._x-a2._x, a1._y-a2._y);
}

int main()
{
	A a1(1,2);
	A a2(4,5);
	A a;
	cout<<"a1: ";
	a1.show();
	cout<<"a2: ";
	a2.show();
	a = a1 + a2;
	cout<<"a: ";
	a.show();
	a = a1 - a2;
	cout<<"a: ";
	a.show();
	return 0;
}


/*
结果:
a1: (_x,_y)=(1,2)
a2: (_x,_y)=(4,5)
a: (_x,_y)=(5,7)
a: (_x,_y)=(-3,-3)
*/