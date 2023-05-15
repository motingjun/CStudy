#include <iostream>

using namespace std;

class Student
{
public:
	void setGrade(string grade);	//设置年级的成员函数
	string getGrade();		//获取年级的成员函数
	void setName(string name);		//设置姓名的成员函数
	string getName();		//获取姓名的成员函数
protected:
	string _grade;		//保护成员：表示年级
private:
	string _name;		//私有成员：表示姓名
};

void Student::setGrade(string grade)	//类外实现setGrade()函数
{
	_grade = grade;
}

string Student::getGrade()
{
	return _grade;
}

void Student::setName(string name)
{
	_name = name;
}

string Student::getName()
{
	return _name;
}


class Undergraduate:public Student
{
public:
	Undergraduate(string major);
	void show();		//声明显示大学生信息的成员函数
private:
	string _major;		//私有成员：表示专业
};


Undergraduate::Undergraduate(string major)
{
	_major = major;
}

void Undergraduate::show()
{
	cout<<"姓名: "<<getName()<<endl;		//派生类调用基类成员函数
	cout<<"年级: "<<getGrade()<<endl;	//派生类访问继承的基类的成员函数
	cout<<"专业: "<<_major<<endl;		//派生类访问新增成员
}


int main()
{
	//创建大学生类对象stu
	Undergraduate stu("计算机信息工程");
	stu.setGrade("大三");		//派生类对象调用基类成员函数设置年级
	stu.setName("张三");			//派生类对象调用基类成员函数设置姓名
	stu.show();		//派生类对象调用新增成员函数显示学生信息
	return 0;
}


/*
结果:
姓名: 张三
年级: 大三
专业: 计算机信息工程
*/


/*
继承方式

1.public(公有继承)
注意:
不可访问成员是指无论在类内还是在类外均不可访问的成员。它与私有成员的区别是，私有成员在类外不可访问，
只能通过类的成员进行访问。不可访问成员完全是由类的派生形成的。对于顶层类，不存在不可访问成员，
但是通过继承，基类的私有成员在派生类内就成为不可访问成员。

2.protected(保护继承)
采用保护继承方式时，基类的公有成员和保护成员在派生类中全部变成保护成员，派生类的其他成员可以直接访问它们，在派生类外无法访问。
基类的私有成员和不可访问成员在派生类中的访问属性是不可访问。

3.private(私有继承)
采用私有继承方式时，基类的公有成员和保护成员在派生类中全部变成私有成员，派生类的其他成员可以直接访问它们，在派生类外无法访问。
基类的私有成员和不可访问成员在派生类中的访问属性是不可访问。
*/