#include <iostream>

using namespace std;

class Solid
{
public:
	Solid(int x, int y, int z):_x(x),_y(y),_z(z){}
	
	void show()
	{
		cout<<"三维坐标"<<_x<<","<<_y<<","<<_z<<endl;
	}
	friend class Point;
private:
	int _x, _y, _z;
};

class Point
{
private:
	int _x, _y;
public:
	Point(int x, int y):_x(x),_y(y){}
	Point(const Solid &another)		//定义转换构造函数
	{
		this->_x=another._x;
		this->_y=another._y;
	}

	void show()
	{
		cout<<"平面坐标:"<<_x<<","<<_y<<endl;
	}
};


int main()
{
	cout<<"原始坐标"<<endl;
	Point p(1,1);
	p.show();
	Solid s(3,4,5);
	s.show();
	cout<<"三维转换平面坐标"<<endl;
	p=s;
	p.show();
	return 0;
}


/*
结果:
原始坐标
平面坐标:1,1
三维坐标3,4,5
三维转换平面坐标
平面坐标:3,4
*/

/*
转换构造函数
转换构造函数指的是构造函数只有一个参数，且参数不是本类的const引用。
用转换构造函数不仅可以将一个标准类型数据转换为类对象，也可以将另一个类的对象转换为转换构造函数所在的类对象。
转换构造函数的语法格式如下所示：
```
class A 
{ 
   A(const B & b) 
   { 
    //从B类类型到A类类型的转换 
   } 
}; 
```
*/


//需要注意的是，由于需要在Point类中访问Solid的成员变量，因此将Solid类声明为Point类的友元类。