//重载构造函数
#include<iostream>
#include<iomanip>

using namespace std;

class Clock
{
public:
	//声明重载构造函数
	Clock(int hour, int min);
	Clock(int hour, int min, int sec=0);
	void showTime();
private:
	int _hour;
	int _min;
	int _sec;	
};

Clock::Clock(int hour, int min):_hour(hour),_min(min)
{
	cout<<"调用两个参数的构造函数"<<endl;
	_sec=10;
}

Clock::Clock(int hour, int min, int sec=0)
{
	cout<<"调用三个参数的构造函数"<<endl;
	_hour=hour;
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
	Clock clock(8,0);		//创建对象clock，传入初始值
	cout<<"clock: ";
	clock.showTime();
	return 0;
}


/*
结果:
编译会报错
overload.cpp:26:37: error: redefinition of default argument
Clock::Clock(int hour, int min, int sec=0)
                                    ^   ~
overload.cpp:12:31: note: previous definition is here
        Clock(int hour, int min, int sec=0);
                                     ^   ~
overload.cpp:43:8: error: call to constructor of 'Clock' is ambiguous
        Clock clock(8,0);               //创建对象clock，传入初始值
              ^     ~~~
overload.cpp:12:2: note: candidate constructor
        Clock(int hour, int min, int sec=0);
        ^
overload.cpp:20:8: note: candidate constructor
Clock::Clock(int hour, int min):_hour(hour),_min(min)
       ^
2 errors generated.
*/


/*
当定义具有默认参数的重载构造函数时，要防止调用的二义性。
在Clock类中定义重载构造函数，并且其中一个构造函数具有默认参数，在创建对象时，构造函数调用会产生二义性。
*/