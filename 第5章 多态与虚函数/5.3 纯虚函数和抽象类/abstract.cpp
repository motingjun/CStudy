#include <iostream>

using namespace std;

class Animal    //动物类Animal
{
public:
	virtual void speak() = 0;	//纯虚函数speak()
	virtual void eat() = 0;		//纯虚函数eat()

	virtual ~Animal();			//虚析构函数
};

Animal::~Animal()
{
	cout<<"调用Animal析构函数"<<endl;
}


class Cat:public Animal    //猫类Cat，公有继承Animal
{
public:
	void speak();	//声明speak()函数
	void eat();		//声明eat()函数

	~Cat();		//声明析构函数
};

void Cat::speak()
{
	cout<<"小猫喵喵叫"<<endl;
}

void Cat::eat()
{
	cout<<"小猫吃鱼"<<endl;
}

Cat::~Cat()
{
	cout<<"调用Cat析构函数"<<endl;
}


class Rabbit:public Animal    //兔子类Rabbit，公有继承Animal类
{
public:
	void speak();	//声明speak()函数
	void eat();		//声明eat()函数

	~Rabbit();	
};


void Rabbit::speak()
{
	cout<<"小兔子咕咕叫"<<endl;
}

void Rabbit::eat()
{
	cout<<"小兔子吃白菜"<<endl;
}

Rabbit::~Rabbit()
{
	cout<<"调用Rabbit析构函数"<<endl;
}


int main()
{
	Animal *pC = new Cat;	//定义基类指针pC指向Cat类
	pC->speak();	//通过pC指针调用Cat类的speak()函数
	pC->eat();
	delete pC;

	Animal *pR = new Rabbit;
	pR->speak();
	pR->eat();
	delete pR;
	return 0;
}


/*
结果:
小猫喵喵叫
小猫吃鱼
调用Cat析构函数
调用Animal析构函数
小兔子咕咕叫
小兔子吃白菜
调用Rabbit析构函数
调用Animal析构函数
*/


/*
纯虚函数也通过virtual关键字声明，但是纯虚函数没有函数体。纯虚函数在声明时，需要在后面加上“=0”，格式如下所示：
```
virtual 函数返回值类型 函数名（参数列表） =  0;
```

如果一个类中包含纯虚函数，这样的类称为抽象类。抽象类的作用主要是通过它为一个类群建立一个公共接口（纯虚函数），
使它们能够更有效地发挥多态性。抽象类声明了公共接口，而接口的完整实现由派生类定义。

抽象类只能作为基类派生新类，不能创建抽象类的对象，但可以定义抽象类的指针或引用，通过指针或引用操作派生类对象。
抽象类可以有多个纯虚函数，如果派生类需要实例化对象，则在派生类中需要全部实现基类的纯虚函数。
如果派生类没有全部实现基类的纯虚函数，未实现的纯虚函数在派生类中仍然是纯虚函数，则派生类也是抽象类。
*/