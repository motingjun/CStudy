#include<iostream>
#include<iomanip>

using namespace std;

class Clock				//定义时钟类Clock
{
public:
	Clock(int hour, int min, int sec);			//声明有参构造函数
	void showTime();	//声明显示时间的成员函数
private:
	int _hour;			//声明表示小时的成员变量
	int _min;			//声明表示分钟的成员变量
	int _sec;			//声明表示秒的成员变量
};

Clock::Clock(int hour, int min, int sec)
{
	_hour=hour;			//初始化过程，将初始值直接赋值给成员变量
	_min=min;
	_sec=sec;
}

void Clock::showTime()
{
	cout<<setw(2)<<setfill('0')<<_hour<<":"
	<<setw(2)<<setfill('0')<<_min<<":"
	<<setw(2)<<setfill('0')<<_sec<<endl;
}

int main()
{
	Clock clock1(10,20,30);		//创建对象clock1，传入初始值
	cout<<"clock1: ";
	clock1.showTime();			//通过对象调用成员函数showTIme()显示时间
	Clock clock2(22,16,12);		//创建对象clock2，传入初始值
	cout<<"clock2: ";
	clock2.showTime();
	return 0;
}


/*
结果:
clock1: 10:20:30
clock2: 22:16:12
*/


/*
需要注意的是，在实现构造函数时，除了在函数体中初始化成员变量，还可以通过“：”运算符在构造函数后面初始化成员变量，
这种方式称为列表初始化，其格式如下所示：

类::构造函数(参数列表): 成员变量1(参数1), 成员变量2(参数2),…, 成员变量n(参数n) 
{ 
    构造函数体 
} 

Clock::Clock(int hour, int min, int sec):_hour(hour),_min(min),_sec(sec)
{
    //...
}


*/