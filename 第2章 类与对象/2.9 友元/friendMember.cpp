#include<iostream>
#include <math.h>

using namespace std;

class Point;
class Circle
{
public:
	float getArea(Point &p1, Point &p2); 	//声明计算面积的成员函数
private:
	const float PI=3.14;
};

class Point
{
	//声明Circle的成员函数getArea()为友元函数
	friend float Circle::getArea(Point &p1, Point &p2);
public:
	Point(float x=0, float y=0);
	~Point();
private:
	float _x;
	float _y;
};

Point::Point(float x, float y):_x(x),_y(y)
{
	cout<<"初始化坐标点"<<endl;
}

Point::~Point(){}

float Circle::getArea(Point &p1, Point &p2)
{
	double x = abs(p1._x - p2._x);		//获取横轴坐标间的距离
	float y = abs(p1._y - p2._y);		//获取纵轴坐标间的距离
	float len = sqrtf(x*x + y*y);		//计算两坐标点之间的距离
	cout<<"获取两个坐标点之间的距离是"<<len<<endl;
	return len*len*PI;					//友元函数访问私有成员变量PI
}


int main(int argc, char const *argv[])
{
	Point p1(5,5);
	Point p2(10,10);
	Circle circle;
	float area = circle.getArea(p1,p2);
	cout<<"圆的面积是: "<<area<<endl;
	return 0;
}


/*
结果:
初始化坐标点
初始化坐标点
获取两个坐标点之间的距离是7.07107
圆的面积是: 157
*/


/*
2.其他类的成员函数作为友元函数
其他类中的成员函数作为本类的友元函数时，需要在本类中表明该函数的作用域，并添加友元函数所在类的前向声明，其语法格式如下：
```
class B;      //声明类B 
class A 
{ 
public： 
 int func();     //声明成员函数func() 
}; 
class B 
{ 
 friend int A::func();   //声明类A的成员函数func()为友元函数 
} 
```
*/