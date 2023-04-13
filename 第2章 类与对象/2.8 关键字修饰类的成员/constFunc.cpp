#include<iostream>

using namespace std;

class Person
{
public:
	Person(string name, int age, string addr, string favFruit);
	~Person();
	
	const string _addr;		//声明表示住址的常成员变量
	void myInfor() const;	//声明显示个人信息的常成员函数
	void myInfor();			//声明显示个人信息的普通成员函数
	void place();			//声明显示住址的常成员变量
private:
	const string _name;		//声明表示姓名的常成员变量
	const int _age;			//声明表示年龄的常成员变量
	string _favFruit;		//声明表示水果的普通成员变量
};

//有参构造函数初始化对象
Person::Person(string name, int age, string addr, string favFruit):
	_name(name),_age(age),_addr(addr),_favFruit(favFruit)
{

}

Person::~Person(){}

//类外实现常成员函数myInfor()
void Person::myInfor() const
{
	// _favFruit="榴莲";
	// place();
	cout<<"我叫"<<_name<<"今年"<<_age<<"岁"<<"我喜欢吃"<<_favFruit<<endl;
}

//类外实现普通成员函数myInfor()
void Person::myInfor()
{
	_favFruit="桃子";
	cout<<"我叫"<<_name<<"今年"<<_age<<"岁"<<"我喜欢吃"<<_favFruit<<endl;
	place();
}

void Person::place()
{
	cout<<"我住在"<<_addr<<endl;
}


int main()
{
	Person p1("张三",18,"北大街","苹果");			//创建对象p1
	p1.myInfor();								//调用普通成员函数myInfor()
	const Person p2("李四",18,"南大街","橘子");	//创建常对象p2
	p2.myInfor();								//调用常成员函数myInfor()
	return 0;
}


/*
结果:
我叫张三今年18岁我喜欢吃桃子
我住在北大街
我叫李四今年18岁我喜欢吃橘子
*/


/*
const修饰成员函数
使用const修饰的成员函数称为常成员函数。与修饰成员变量不同的是，修饰成员函数时，const位于成员函数的后面，其格式如下：
```
返回值类型  函数名() const; 
```
在常成员函数内部，只能访问类的成员变量，而不能修改类的成员变量；并且，常成员函数只能调用类的常成员函数，而不能调用类的非常成员函数。

类中定义的成员函数若与常成员函数名相同则构成重载，常成员函数只能由const修饰的对象进行访问。
*/

