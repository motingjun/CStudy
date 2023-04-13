#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Rabbit	//定义兔子类Rabbit
{
public:
	Rabbit(string name, const char* pf);		//声明构造函数
	~Rabbit();								//声明析构函数
	
	void eat();
private:
	string _name;	//声明表示兔子名字的成员变量
	char* _food;	//声明表示兔子食物的成员变量
};

Rabbit::Rabbit(string name, const char* pf)
{
	cout<<"调用构造函数"<<endl;
	_name = name;
	_food=new char[50];		//为_food指针申请空间
	memset(_food,0,50);		//初始化_food空间
	strcpy(_food,pf);		//将参数pf指向的数据复制到_food中
}

Rabbit::~Rabbit()
{
	cout<<"调用析构函数, 析构"<<_name<<endl;
	if (_food != NULL)
		delete []_food;
}

void Rabbit::eat()
{
	cout<<_name<<" is eating "<<_food<<endl;
}

int main()
{
	Rabbit A("A","luobo");
	A.eat();
	Rabbit B("B","baicai");
	B.eat();
	return 0;
}


/*
结果:
调用构造函数
A is eating luobo
调用构造函数
B is eating baicai
调用析构函数, 析构B
调用析构函数, 析构A
*/