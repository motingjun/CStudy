#include <iostream>

using namespace std;

class Wood    //木材类Wood
{
public:
	Wood(){cout<<"木材构造函数"<<endl;}
	~Wood(){cout<<"木材析构函数"<<endl;}	
};


class Sofa    //沙发类Sofa
{
public:
	Sofa(){cout<<"沙发构造函数"<<endl;}
	~Sofa(){cout<<"沙发析构函数"<<endl;}
	
	void sit(){cout<<"Sofa用来坐..."<<endl;}
};

class Bed    //床类Bed
{
public:
	Bed(){cout<<"床的构造函数"<<endl;}
	~Bed(){cout<<"床的析构函数"<<endl;}

	void sleep(){cout<<"bt_decode_req用来睡觉..."<<endl;}	
};


class Sofabed:public Sofa, public Bed
{
public:
	Sofabed(){cout<<"沙发床构造函数"<<endl;}
	~Sofabed(){cout<<"沙发床析构函数"<<endl;}

	Wood pearwood;		//Wood对象pearwood	
};


int main()
{
	Sofabed sbed;
	sbed.sit();
	sbed.sleep();
	return 0;
}


/*
结果:
沙发构造函数
床的构造函数
木材构造函数
沙发床构造函数
Sofa用来坐...
bt_decode_req用来睡觉...
沙发床析构函数
木材析构函数
床的析构函数
沙发析构函数
*/


/*
在多继承中，派生构造函数的定义格式如下所示：
```
派生类构造函数名(参数列表):基类1构造函数名(参数列表), 基类2构造函数名(参数列表), … 
{ 
 派生类新增成员的初始化语句 
} 
```


如果派生类中有成员对象，构造函数的调用顺序是：首先按照继承顺序依次调用基类构造函数，
然后调用成员对象的构造函数，最后调用派生类构造函数。
*/