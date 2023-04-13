#include<iostream>

using namespace std;

class Circle
{
	friend void getArea(Circle &circle);	//声明普通函数getArea()为友元函数
private:
	float _radius;
	const float PI=3.14;
public:
	Circle(float radius=0);
	~Circle();
};

Circle::Circle(float radius):_radius(radius)
{
	cout<<"初始化圆的半径: "<<_radius<<endl;
}

Circle::~Circle(){}

void getArea(Circle &circle)
{
	//访问类中的成员变量
	cout<<"圆的半径是: "<<circle._radius<<endl;
	cout<<"圆的面积是: "<<circle.PI*circle._radius*circle._radius<<endl;
	cout<<"友元函数修改半径:"<<endl;
	circle._radius = 1;
	cout<<"圆的半径是: "<<circle._radius<<endl;
}


int main(int argc, char const *argv[])
{
	Circle circle(10);
	getArea(circle);
	return 0;
}


/*
结果:
初始化圆的半径: 10
圆的半径是: 10
圆的面积是: 314
友元函数修改半径:
圆的半径是: 1
*/


/*
友元函数可以是类外定义的函数或者是其他类中的成员函数，若在类中声明某一函数为友元函数，则该函数可以操作类中的所有数据。

1.普通函数作为友元函数
将普通函数作为类的友元函数，在类中使用friend关键字声明该普通函数就可以实现，友元函数可以在类中任意位置声明。
普通函数作为类的友元函数的声明格式如下所示：
```
class 类名 
{ 
   friend 函数返回值类型 友元函数名（形参列表）; 
   ...   //其他成员 
} 
```

普通函数作为友元函数访问了类中的私有成员，且具有修改私有成员的权限。
*/