#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base();	//虚析构函数
};

Base::~Base()
{
	cout<<"Base类虚析构函数"<<endl;
}


class Derive:public Base    //派生类Derive，公有继承Base类
{
public:
	~Derive();		//虚析构函数	
};

Derive::~Derive()
{
	cout<<"Derive类虚析构函数"<<endl;
}


int main()
{
	Base *pb = new Derive;	//基类指针指向派生类对象
	delete pb;				//释放基类指针
	return 0;
}


/*
结果:
Derive类虚析构函数
Base类虚析构函数
*/


/*
虚析构函数：

在C++中不能声明虚构造函数，因为构造函数执行时，对象还没有创建，不能按照虚函数方式调用。
但是，在C++中可以声明虚析构函数，虚析构函数的声明是在“～”符号前添加virtual关键字，格式如下所示：
```
virtual ~析构函数(); 
```

在基类中声明虚析构函数之后，基类的所有派生类的析构函数都自动成为虚析构函数。

在基类声明虚析构函数之后，使用基类指针或引用操作派生类对象，在析构派生类对象时，编译器会先调用派生类的析构函数释放派生类对象资源，然后再调用基类析构函数。
如果基类没有声明虚析构函数，在析构派生类对象时，编译器只会调用基类析构函数，不会调用派生类析构函数，导致派生类对象申请的资源不能正确释放。
*/