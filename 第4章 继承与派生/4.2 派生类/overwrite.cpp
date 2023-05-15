#include <iostream>

using namespace std;

class Vehicle
{
public:
	void run();
};

void Vehicle::run()
{
	cout<<"基类run()函数: 行驶"<<endl;
}

class Car : public Vehicle
{
public:
	void run();
};

void Car::run()
{
	cout<<"小汽车需要燃烧汽油，行驶速度快"<<endl;
}

int main(int argc, char const *argv[])
{
	Car car;				//创建小汽车类对象car
	car.run();				//调用派生类的run()函数
	car.Vehicle::run();		//调用基类名与作用域限定符调用基类run()函数
	Vehicle *pv = &car;
	pv->run();
	return 0;
}

/*
结果:
小汽车需要燃烧汽油，行驶速度快
基类run()函数: 行驶
基类run()函数: 行驶
*/


/*
在派生类中重新定义基类同名函数，基类同名函数在派生类中被隐藏，通过派生类对象调用同名函数时，
调用的是改写后的派生类成员函数，基类同名函数不会被调用。如果想通过派生类对象调用基类的同名函数，
需要使用作用域限定符“::”指定要调用的函数，或者根据类型兼容规则，通过基类指针调用同名成员函数。
*/