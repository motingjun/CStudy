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
	_home=another._home;	//浅拷贝
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
结果: 异常
调用构造函数
sheepA:Doly white beijing
调用拷贝构造函数
sheepB:Doly white beijing
调用析构函数
调用析构函数
simple(44028,0x1180abdc0) malloc: *** error for object 0x7ff115c05870: pointer being freed was not allocated
simple(44028,0x1180abdc0) malloc: *** set a breakpoint in malloc_error_break to debug
[1]    44028 abort      ./simple
*/

/*
异常原因:
在浅拷贝过程中，对象sheepA中的_home指针与对象sheepB中的_home指针指向同一块内存空间。当程序运行结束时，
析构函数释放对象所占用资源，析构函数先析构对象sheepB，后析构对象sheepA。
在析构sheepB对象时释放了_home指向的堆内存空间的数据，当析构sheepA时_home指向的堆内存空间已经释放，
再次释放内存空间的资源，程序运行异常终止，即存储“beijing”的堆内存空间被释放了两次，
因此程序抛出异常，这种现象被称重析构（double free）。
*/