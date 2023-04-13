#include<iostream>

using namespace std;

class Birth			//定义出生日期类Birth
{
public:
	Birth(int year, int month, int day);
	void show();	//声明成员函数show()显示日期
private:
	int _year;
	int _month;
	int _day;
};

//类外实现构造函数
Birth::Birth(int year, int month, int day):_year(year),_month(month),_day(day)
{
	cout<<"Birth类构造函数"<<endl;
}

//类外实现show()函数
void Birth::show()
{
	cout<<"出生日期: "<<_year<<"-"<<_month<<"-"<<_day<<endl;
}


class Student		//定义学生类Student
{
public:
	//构造函数
	Student(string name, int id, int year, int month, int day);
	void show();
private:
	string _name;
	int _id;
	Birth birth;
};

//类外实现构造函数
Student::Student(string name, int id, int year, int month, int day):birth(year,month,day)
{
	cout<<"Student类构造函数"<<endl;
	_name=name;
	_id=id;
}

//类外实现show()函数
void Student::show()
{
	cout<<"姓名: "<<_name<<endl;
	cout<<"学号: "<<_id<<endl;
	birth.show();
}


int main()
{
	Student stu("lili",10002,2000,1,1);	//创建学生对象stu
	stu.show();	//显示学生信息
	return 0;
}


/*
结果:
Birth类构造函数
Student类构造函数
姓名: lili
学号: 10002
出生日期: 2000-1-1
*/


/*
C++允许将一个对象作为另一个类的成员变量，即类中的成员变量可以是其他类的对象，
这样的成员变量称为类的子对象或成员对象。含有成员对象的类的定义格式如下所示：

class B 
{ 
  A a;   //对象a作为类B的成员变量 
  ...   //其他成员 
} 


创建含有成员对象的对象时，先执行成员对象的构造函数，再执行类的构造函数。
例如，上述格式中，类B包含一个类A对象作为成员变量，在创建类B对象时，
先执行类A的构造函数，将类A对象创建出来，再执行类B的构造函数，创建类B对象。
如果类A构造函数有参数，其参数要从类B的构造函数中传入，且必须以“：”运算符初始化类A对象。
*/