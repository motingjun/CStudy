#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

class Sheep
{
public:
	Sheep(string name, string color, const char* home);
	Sheep(const Sheep& another);	//声明拷贝构造函数
	~Sheep();
	
	void show();
private:
	string _name;
	string _color;
	char* _home;	//声明表示绵羊加家的成员变量
};

Sheep::Sheep(string name, string color, const char* home)
{
	cout<<"调用构造函数"<<endl;
	_name=name;
	_color=color;
	//为指针成员home分配空间，将形参home的内容复制到_home指向的空间
	int len=strlen(home)+1;
	_home=new char[len];
	memset(_home,0,len);
	strcpy(_home,home);
}

Sheep::Sheep(const Sheep& another)
{
	cout<<"调用拷贝构造函数"<<endl;
	_name=another._name;
	_color=another._color;
	//完成深拷贝
	int len = strlen(another._home);
	_home = new char[len];
	strcpy(_home,another._home);
}

Sheep::~Sheep()
{
	cout<<"调用析构函数"<<endl;
	if (_home != NULL)
		delete []_home;
}

void Sheep::show()
{
	cout<<_name<<" "<<_color<<" "<<_home<<endl;
}

int main()
{
	const char *p = "beijing";
	Sheep sheepA("Doly","white",p);
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
sheepA:Doly white beijing
调用拷贝构造函数
sheepB:Doly white beijing
调用析构函数
调用析构函数
*/


/*
所谓深拷贝，就是在拷贝构造函数中完成更深层次的复制，当类中有指针成员时，深拷贝可以为新对象的指针分配一块内存空间，将数据复制到新空间。
对象sheepA中的_hom e指针与对象sheepB中的_hom e指针指向不同的内存空间，在析构时，析构各自对象所占用的资源不会再产生冲突。
*/