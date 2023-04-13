#include<iostream>

using namespace std;

class Student		//定义学生类Student
{
public:				//公有类型
	void study();	//声明表示学习的成员函数
	void exam();	//声明表示考试的成员函数
	string _name;	//声明表示姓名的成员变量
	int _age;		//声明表示年龄的成员变量
};

void Student::study()	//类外实现study()成员函数
{
	cout << "学习C++" << endl;
}

void Student::exam()	//类外实现exam()成员函数
{
	cout << "C++考试成绩100分" << endl;
}

int main()
{
	Student stu;			//创建Student类对象stu
	stu._name = "张三";		//设置对象stu的姓名
	stu._age = -20;			//设置对象stu的年龄
	cout << stu._name << stu._age << "岁" << endl;
	stu.study();			//调用study()成员函数
	stu.exam();				//调用exam()成员函数
	return 0;
}


/*
结果:
张三-20岁
学习C++
C++考试成绩100分
*/


/*
类是对象的模板，对象是类的实体。

public（公有类型）：被public修饰的成员也称为公有成员。公有成员是类的外部接口，可以被所属类的成员函数、类对象、派生类对象、友元函数、友元类访问。
protected（保护类型）：被protected修饰的成员称为保护成员，其访问权限介于私有和公有之间，可以被所属类的成员函数、派生类对象、友元类和友元函数访问。
private（私有类型）：被private修饰的成员称为私有成员，只能被所属类的成员函数、友元函数、友元类访问。

注意:
1) 创建对象时应当为每个对象分配独立的内存空间存储成员变量的值。
2) C++用同一块空间存放同类对象的成员函数代码，每个对象调用同一段代码。
*/