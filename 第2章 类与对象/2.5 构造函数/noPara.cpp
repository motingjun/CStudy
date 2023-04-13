#include<iostream>
#include<iomanip>

using namespace std;

class Clock				//定义时钟类Clock
{
public:
	Clock();			//声明无参构造函数
	void showTime();	//声明显示时间的成员函数
private:
	int _hour;			//声明表示小时的成员变量
	int _min;			//声明表示分钟的成员变量
	int _sec;			//声明表示秒的成员变量
};

Clock::Clock()			//类外实现无参构造函数
{
	_hour=0;			//初始化过程，将成员变量初始化为0
	_min=0;
	_sec=0;
}

void Clock::showTime()
{
	cout<<setw(2)<<setfill('0')<<_hour<<":"
	<<setw(2)<<setfill('0')<<_min<<":"
	<<setw(2)<<setfill('0')<<_sec<<endl;
}

int main()
{
	Clock clock;		//创建对象clock
	cout<<"clock: ";
	clock.showTime();	//通过对象调用成员函数showTime()显示时间
	return 0;
}


/*
结果:
clock: 00:00:00
*/


/*
关于构造函数定义格式的说明，具体如下。
1）构造函数名必须与类名相同。
2）构造函数名的前面不需要设置返回值类型。
3）构造函数中无返回值，不能使用return返回。
4）构造函数的成员权限控制符一般设置为public。
*/