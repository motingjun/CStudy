#include<iostream>
#include<math.h>

using namespace std;

//定义坐标点类Point
class Point
{
public:
	Point(float x=0, float y=0);
	~Point();
	
	static float getLen(Point& p1, Point& p2);		//声明静态成员函数
	static float _len;		//声明静态成员变量_len
private:
	float _x;
	float _y;	
};

float Point::_len = 0;

//类外实现有参构造函数
Point::Point(float x, float y):_x(x),_y(y)
{
	cout<<"初始化坐标点"<<endl;
}

Point::~Point(){}

float Point::getLen(Point &p1, Point &p2)
{
	float x = abs(p1._x - p2._x);
	float y = abs(p1._y - p2._y);
	_len = sqrtf(x*x + y*y);
	return _len;
}


int main(int argc, char const *argv[])
{
	Point p1(1,2);
	Point p2(6,8);
	cout<<Point::getLen(p1,p2)<<endl;
	return 0;
}


/*
结果:
初始化坐标点
初始化坐标点
7.81025
*/


/*
static修饰成员函数
类中定义的普通函数只能通过对象调用，无法使用类调用。使用static修饰的成员函数，同静态成员变量一样，可以通过对象或类调用。

静态成员函数可以直接访问类中的静态成员变量和静态成员函数，对外提供了访问接口，实现了静态成员变量的管理。
需要注意的是，静态成员函数属于类，不属于对象，没有this指针。
*/

/*
static conts修饰符组合修饰类成员
使用static const修饰符组合修饰类成员，既实现了数据共享又达到了数据不被改变的目的。
此时，修饰成员函数与修饰普通函数格式一样，修饰成员变量必须在类的内部进行初始化。示例如下：
```
class Point 
{ 
public: 
     const static float getLen(); 
private: 
     const static float area; 
}; 
const float area=3600;
```
*/