#include<iostream>

using namespace std;

class Student					//定义学生类Student
{
public:							//公有类型
	void study();				//声明表示学习的成员函数
	void exam();				//声明表示考试的成员函数
	void setName(string name);	//声明设置姓名的成员函数
	void setAge(int age);		//声明设置年龄的成员函数
	string getName();			//声明获取姓名的成员函数
	int getAge();				//声明获取年龄的成员函数
private:						//私有类型
	string _name;				//声明表示姓名的成员变量
	int _age;					//声明表示年龄的成员变量
};

void Student::study()			//类外实现study()成员函数
{
	cout << "学习C++" << endl;
}

void Student::exam()
{
	cout << "C++考试成绩100分" << endl;
}

void Student::setName(string name)
{
	_name = name;
}

void Student::setAge(int age)
{
	if (age < 0 || age > 100)
	{
		cout << _name << "年龄输入错误" << endl;
		_age = 0;
	}
	else
		_age = age;
}

string Student::getName()
{
	return _name;
}

int Student::getAge()
{
	return _age;
}


int main()
{
	Student stu;			//创建Student类对象stu
	stu.setName("张三");		//设置对象stu的姓名
	stu.setAge(-20);		//设置对象stu的年龄
	//调用成员函数getName()和getAge()获取对象stu的姓名、年龄，并输出
	cout << stu.getName() << stu.getAge() << "岁" << endl;
	stu.study();			//调用成员函数study()
	stu.exam();				//调用成员函数exam()

	Student stu1;			//创建Student类对象stu1
	stu1.setName("李四");
	stu1.setAge(22);
	cout << stu1.getName() << stu1.getAge() << "岁" << endl;
	stu1.study();
	stu1.exam();
	return 0;
}


/*
结果:
张三年龄输入错误
张三0岁
学习C++
C++考试成绩100分
李四22岁
学习C++
C++考试成绩100分
*/


/*
C++中的封装是通过类实现的，通过类把具体事物抽象为一个由属性和行为结合的独立单位，
类的对象会表现出具体的属性和行为。在类的封装设计中通过权限控制方式实现类成员的访问，
目的是隐藏对象的内部实现细节，只对外提供访问的接口。

通过权限控制符可以限制外界对类的成员变量的访问，将对象的状态信息隐藏在对象内部，
通过类提供的函数（接口）实现对类中成员的访问。在定义类时，将类中的成员变量设置为私有或保护属性，
即使用private或protected关键字修饰成员变量。使用类提供的公有成员函数（public修饰的成员函数），
如用于获取成员变量值的getXxx()函数和用于设置成员变量值的setXxx()函数，操作成员变量的值。
*/