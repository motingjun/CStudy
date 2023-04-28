#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

using namespace std;

class Assign
{
public:
	char* name;
	char* url;
public:
	Assign(const char* name, const char* url);
	Assign(const Assign& temp);		//拷贝构造函数
	~Assign()
	{
		delete []name;
		delete []url;
	}
	Assign& operator=(Assign& temp);	//赋值运算重载
};

Assign::Assign(const char* name, const char* url)
{
	this->name=new char[strlen(name)+1];
	this->url=new char[strlen(url)+1];
	if(name)
		strcpy(this->name,name);
	if(url)
		strcpy(this->url,url);
}

Assign::Assign(const Assign& temp)
{
	this->name=new char[strlen(temp.name)+1];
	this->url=new char[strlen(temp.url)+1];
	if(name)
		strcpy(this->name,temp.name);
	if(url)
		strcpy(this->url,temp.url);
}

Assign& Assign::operator=(Assign& temp)
{
	delete []name;
	delete []url;	//先释放原来空间，再重新申请
	this->name=new char[strlen(temp.name)+1];
	this->url=new char[strlen(temp.url)+1];
	if(name)
		strcpy(this->name,temp.name);
	if(url)
		strcpy(this->url,temp.url);
	return *this;
}


int main()
{
	Assign a("传智播客", "http://net.itcast.cn/");
	cout<<"a对象: "<<a.name<<" "<<a.url<<endl;
	Assign b(a);	//用a对象初始化b, 调用的是拷贝构造函数
	cout<<"b对象: "<<b.name<<" "<<b.url<<endl;
	Assign c("黑马训练营", "http://www.itheima.com/");
	cout<<"c对象: "<<c.name<<" "<<c.url<<endl;
	b=c;	//调用赋值重载函数
	cout<<"b对象: "<<b.name<<" "<<b.url<<endl;
	return 0;
}


/*
结果:
a对象: 传智播客 http://net.itcast.cn/
b对象: 传智播客 http://net.itcast.cn/
c对象: 黑马训练营 http://www.itheima.com/
b对象: 黑马训练营 http://www.itheima.com/
*/

//赋值运算符重载