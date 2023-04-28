#include <iostream>

using namespace std;

class A
{
private:
	int _x;
	int _y;
public:
	A(int x=0, int y=0):_x(x),_y(y){}
	~A(){}

	void show() const;	//输出数据
	A operator+(const A& a) const;	//重载"+"运算符
	A operator-(const A& a) const;	//重载"-"运算符
};

void A::show() const
{
	cout<<"(_x,_y)="<<"("<<_x<<","<<_y<<")"<<endl;
}

A A::operator+(const A& a) const
{
	return A(_x+a._x, _y+a._y);
}

A A::operator-(const A& a) const
{
	return A(_x-a._x, _y-a._y);
}


int main(int argc, char const *argv[])
{
	A a1(1,2);
	A a2(4,5);
	A a;
	cout<<"a1: ";
	a1.show();
	cout<<"a2: ";
	a2.show();
	a = a1 + a2;	//实现两个对象相加
	cout<<"a: ";
	a.show();
	a = a1 - a2;	//实现两个对象相减
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


/*
在C++中，运算符的操作对象可以是基本的数据类型，也可以是类中重新定义的运算符，赋予运算符新的功能，对类对象进行相关操作。
在类中重新定义运算符，赋予运算符新的功能以适应自定义数据类型的运算，就称为运算符重载。

在C++中，使用operator关键字定义运算符重载。运算符重载语法格式如下：
```
返回值类型 operator 运算符名称 (参数列表) 
{ 
 ...//函数体 
} 
```

重载运算符并没有改变其原来的功能，只是增加了针对自定义数据类型的运算功能，具有了更广泛的多态特征。
*/