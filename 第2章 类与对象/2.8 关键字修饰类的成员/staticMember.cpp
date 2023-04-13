#include<iostream>

using namespace std;

class Student
{
public:
	Student(string name);
	~Student();
	
	static int _sum;	//声明表示学生总数的静态成员变量
private:
	string _name;		//声明表示学生姓名的成员变量
};

Student::Student(string name)
{
	this->_name=name;
	_sum++;
}

Student::~Student()
{
}

int Student::_sum = 0;	//类外初始化静态成员变量_sum


int main()
{
	Student stu1("张三");
	Student stu2("李四");
	cout<<"人数是:"<<stu1._sum<<endl;	//通过对象访问静态成员变量
	cout<<"人数是:"<<stu2._sum<<endl;
	cout<<"stu1的大小是:"<<sizeof(stu1)<<endl;
	return 0;
}


/*
结果:
人数是:2
人数是:2
stu1的大小是:24
*/


/*
类中的成员变量，在某些时候被多个类的对象共享，实现对象行为的协调作用。共享数据通过static实现，用static修饰成员后，创建的对象都共享一个静态成员。
static既可以修饰类的成员变量，也可以修饰类的成员函数。

static修饰的静态成员变量只能在类内部定义，在类外部初始化。静态成员变量在调用时，可以通过对象和类进行访问。
由于static成员变量存储在类的外部，计算类的大小时不包含在内。
*/
