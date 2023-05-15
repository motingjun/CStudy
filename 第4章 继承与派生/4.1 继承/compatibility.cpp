#include <iostream>

using namespace std;

class Base  	//定义基类Base
{
public:
	Base();
	void show();
protected:
	string _name;
};

Base::Base()
{
	_name = "base";
}

void Base::show()
{
	cout<<_name<<" Base show()"<<endl;
}


class Derive:public Base  	//Derive类公有继承Base类
{
public:
	Derive();
	void display();
};

Derive::Derive()
{
	_name = "derive";
}

void Derive::display()
{
	cout<<_name<<" Derive show()"<<endl;
}

void func(Base* pbase)
{
	pbase->show();
}


int main(int argc, char const *argv[])
{
	Derive derive;			//创建Derive类对象derive
	Base base = derive;		//使用对象derive为Base类对象base赋值
	Base &qbase = derive;	//使用对象derive为Base类对象的引用qbase赋值
	Base *pbase = &derive;	//使用独享derive的地址为Base类指针pbase赋值

	base.show();
	qbase.show();
	pbase->show();		//通过Base类指针调用show()函数
	func(&derive);		//取对象derive的地址作为func()函数的参数
	return 0;
}


/*
结果:
derive Base show()
derive Base show()
derive Base show()
derive Base show()
*/


/*
类型兼容
在C++中，基类与派生类之间也存在类型兼容。通过公有继承，派生类获得了基类除构造函数、析构函数之外的所有成员。
公有派生类实际上就继承了基类所有公有成员。因此，在语法上，公有派生类对象总是可以充当基类对象，
即可以将公有派生类对象赋值给基类对象，在用到基类对象的地方可以用其公有派生类对象代替。

C++中的类型兼容情况主要有以下几种：
1）使用公有派生类对象为基类对象赋值；
2）使用公有派生类对象为基类对象的引用赋值；
3）使用公有派生类对象的指针为基类指针赋值；
4）如果函数的参数是基类对象、基类对象的引用、基类指针，则函数在调用时，可以使用公有派生类对象、公有派生类对象的地址作为实参。

虽然可以使用公有派生类对象代替基类对象，但是通过基类对象只能访问基类的成员，无法访问派生类的新增成员。
*/