#include <iostream>

using namespace std;

class Animal  	//定义动物类Animal
{
public:
	void move();	//声明表示动物行为的成员函数move()
};

void Animal::move()
{
	cout<<"动物行为"<<endl;
}


class Cat:public Animal  	//定义猫类Cat，公有继承动物类Animal
{
public:
	Cat(string name);	//成员变量：表示名字	
	void walk();		//声明表示动物行为的普通成员函数walk()
private:
	string _name;		//成员变量：表示名字
};

Cat::Cat(string name)
{
	_name = name;
}

void Cat::walk()
{
	cout<<_name<<"会走"<<endl;
}


int main(int argc, char const *argv[])
{
	Cat cat("猫");	//定义猫类对象cat
	cat.move();		//通过派生类对象调用基类成员函数
	cat.walk();		//通过派生类对象调用新增的成员函数
	return 0;
}


/*
结果:
动物行为
猫会走
*/


/*
在C++中，声明一个类继承另一个类的格式如下所示：
```
class 派生类名称:继承方式  基类名称 
{ 
 派生类成员声明 
};
```

在类的继承中，有以下几点需要注意。
1）基类的构造函数和析构函数不能被继承。
2）派生类对基类的成员的继承没有选择权，不能选择继承或不继承某些成员。
3）派生类中可以增加新的成员，用于实现新功能，保证派生类的功能在基类基础上有所拓展。
4）一个基类可以派生出多个派生类；一个派生类也可以继承自多个基类。

通过继承，基类中的所有成员（构造函数和析构函数除外）被派生类继承，成为派生类成员。
*/