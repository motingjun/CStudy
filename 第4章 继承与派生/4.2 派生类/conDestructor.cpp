#include <iostream>

using namespace std;

class Engine   	//定义发动机类Engine
{
public:
	Engine(string type, int power);		//发动机构造函数

	void show();	//发动机普通成员函数show()
	~Engine();		//发动机析构函数
private:
	string _type;	//成员_type表示型号
	int _power;		//成员_power表示功率
};

Engine::Engine(string type, int power)
{
	cout<<"调用发动机Engine构造函数"<<endl;
	_type = type;
	_power = power;
}

void Engine::show()
{
	cout<<"发动机型号: "<<_type<<",发动机功率: "<<_power<<endl;
}

Engine::~Engine()
{
	cout<<"调用发动机Engine析构函数"<<endl;
}


class Vehicle		//定义交通工具类Vehicle   
{
public:
	Vehicle(string name);
	~Vehicle();

	void run();			//交通工具类欧通成员函数run()
	string getName();	//交通工具类欧通成员函数getName()
private:
	string _name;	
};

Vehicle::Vehicle(string name)
{
	cout<<"调用交通工具Vehicle构造函数"<<endl;
	_name = name;
}

void Vehicle::run()
{
	cout<<_name<<"正在行驶中"<<endl;
}

string Vehicle::getName()
{
	return _name;
}


Vehicle::~Vehicle()
{
	cout<<"调用交通工具Vehicle析构函数"<<endl;
}


//定义小汽车类Car，公有继承交通工具类Vehicle
class Car : public Vehicle
{
public:
	//小汽车类构造函数，其参数包括了成员对象、基类成员变量、新增成员变量的参数
	Car(int seats, string color, string type, int power, string name);
	~Car();
	
	void brake();	//小汽车类普通成员函数brake()
	void display();	//小汽车类普通成员函数display()

	Engine engine;	//公有成员变量，Engine类对象
private:
	int _seats;		//成员_seats表示作为数量
	string _color;	//成员_color表示颜色
};

//类外实现构造函数，后面使用":"运算符调用成员对象构造函数、基类构造函数
Car::Car(int seats, string color, string type, int power, string name) :
	engine(type,power),Vehicle(name)
{
	cout<<"调用小汽车Car构造函数"<<endl;
	_seats = seats;
	_color = color;
}

void Car::brake()
{
	cout<<getName()<<"停车"<<endl;
}

void Car::display()
{
	cout<<getName()<<"有"<<_seats<<"个座位，颜色为"<<_color<<endl;
}

Car::~Car()
{
	cout<<"调用小汽车Car析构函数"<<endl;
}


int main()
{
	Car car(5, "red", "EA113", 130, "passat");		//创建小汽车类对象car
	car.run();
	car.brake();
	car.display();

	//通过成员对象engine调用Engine类的show()函数，显示发动机信息
	car.engine.show();
	return 0;
}


/*
结果:
调用交通工具Vehicle构造函数
调用发动机Engine构造函数
调用小汽车Car构造函数
passat正在行驶中
passat停车
passat有5个座位，颜色为red
发动机型号: EA113,发动机功率: 130
调用小汽车Car析构函数
调用发动机Engine析构函数
调用交通工具Vehicle析构函数
*/

/*
关于派生类构造函数的定义，有以下几点需要注意：
1）派生类构造函数与基类构造函数的调用顺序是，先调用基类构造函数再调用派生类构造函数。
2）派生类构造函数的参数列表中需要包含派生类新增成员变量和基类成员变量的参数值。
调用基类构造函数时，基类构造函数从派生类的参数列表中获取实参，因此不需要类型名。
3）如果基类没有构造函数或仅存在无参构造函数，则在定义派生类构造函数时可以省略对基类构造函数的调用。
4）如果基类定义了有参构造函数，派生类必须定义构造函数，提供基类构造函数的参数，完成基类成员变量的初始化。

注意：
虽然公有派生类的构造函数可以直接访问基类的公有成员变量和保护成员变量，甚至可以在构造函数中对它们进行初始化，
但一般不这样做，而是通过调用基类的构造函数对它们进行初始化，再调用基类接口（普通成员函数）访问它们。这样可以降低类之间的耦合性。
*/