#include <iostream>

using namespace std;

class Time  	//定义Time类，描述时分秒
{
public:
	Time(int hour, int minute, int second);
	friend class Date;		//声明类Date为友元类
private:
	int _hour, _minute, _second;
};

class Date   	//定义Date类
{
public:
	Date(int year, int month, int day);
	void showTime(Time& time);
private:
	int _year, _month, _day;
};

Date::Date(int year, int month, int day)
{
	_year=year;
	_month=month;
	_day=day;
}

void Date::showTime(Time& time)
{
	cout<<_year<<"-"<<_month<<"-"<<_day<<" "<<time._hour<<":"<<time._minute<<":"<<time._second<<endl;
}

Time::Time(int hour, int minute, int second):
	_hour(hour),_minute(minute),_second(second)
{

}


int main(int argc, char const *argv[])
{
	Time time(17,30,20);
	Date date(2019,10,31);
	date.showTime(time);
	return 0;
}


/*
结果:
2019-10-31 17:30:20
*/


/*
友元类：
友元类可以声明在类中任意位置。声明友元类之后，友元类中的所有成员函数都是该类的友元函数，能够访问该类的所有成员。
与声明友元函数类似，友元类也是使用关键字friend声明，其语法格式如下：
```
class B；         //类B前向声明 
class A 
{ 
}; 
class B 
{ 
 friend class A；       //声明类A是类B的友元类 
} 
```
*/


/*
使用友元类需要注意以下几点:
1）友元声明位置由程序设计者决定，且不受类中public、private、protected权限控制符的影响。
2）友元关系是单向的，即类A是类B的友元，但B不是A的友元。
3）友元关系不具有传递性，即类C是类D的友元，类E是类C的友元，但类E不是类D的友元。
4）友元关系不能被继承。
*/