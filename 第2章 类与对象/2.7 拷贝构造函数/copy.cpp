#include<iostream>

using namespace std;

class Sheep		//定义绵羊类Sheep
{
public:
	Sheep(string name, string color);	//声明有参构造函数
	Sheep(const Sheep& another);		//声明拷贝构造函数
	~Sheep();							//声明析构函数
	
	void show();	//声明普通成员函数
private:
	string _name;	//声明表示绵羊名字的成员变量
	string _color;	//声明表示绵羊颜色的成员变量
};

Sheep::Sheep(string name, string color)
{
	cout<<"调用构造函数"<<endl;
	_name=name;
	_color=color;
}

Sheep::Sheep(const Sheep& another)	//类外实现拷贝构造函数
{
	cout<<"调用拷贝构造函数"<<endl;
	_name=another._name;
	_color=another._color;
}

Sheep::~Sheep()
{
	cout<<"调用析构函数"<<endl;
}

void Sheep::show()
{
	cout<<_name<<" "<<_color<<endl;
}

int main()
{
	Sheep sheepA("Doly","white");
	cout<<"sheepA:";
	sheepA.show();
	Sheep sheepB(sheepA);	//使用sheepA初始化新对象sheepB
	cout<<"sheepB:";
	sheepB.show();
	return 0;
}


/*
结果:
调用构造函数
sheepA:Doly white
调用拷贝构造函数
sheepB:Doly white
调用析构函数
调用析构函数
*/


/*
拷贝构造函数是一种特殊的构造函数，它具有构造函数的所有特性，并且使用本类对象的引用作为形参，
能够通过一个已经存在的对象初始化该类的另一个对象。拷贝构造函数的定义格式如下所示：
```
class 类名 
{ 
public: 
 构造函数名称(const 类名& 对象名) 
 { 
   函数体 
 } 
 ...  //其他成员 
}; 
```
在定义拷贝构造函数时，为了使引用的对象不被修改，通常使用const修饰引用的对象。


拷贝构造函数调用情况有以下三种:
1）使用一个对象初始化另一个对象。
2）对象作为参数传递给函数。当函数的参数为对象时，编译器会调用拷贝构造函数将实参传递给形参。
3）函数返回值为对象。当函数返回值为对象时，编译器会调用拷贝构造函数将返回值复制到临时对象中，将数据传出。
*/