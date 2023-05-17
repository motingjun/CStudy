#include <iostream>

using namespace std;

class Animal    //动物类Animal
{
public:
	virtual void speak();	//声明虚函数speak()
};

void Animal::speak()
{
	cout<<"动物叫声"<<endl;
}


class Cat:public Animal		//猫类Cat，公有继承Animal类
{
public:
	virtual void speak();	//声明虚函数speak()
};

void Cat::speak()
{
	cout<<"猫的叫声：喵喵"<<endl;
}


class Dog:public Animal
{
public:
	virtual void speak();
};

void Dog::speak()
{
	cout<<"狗的叫声：汪汪"<<endl;
}


int main()
{
	Cat cat;			//创建Cat类对象cat
	Animal *pA = &cat;	//定义Animal类指针pA指向对象cat
	pA->speak();		//通过pA调用speak()函数

	Dog dog;
	Animal *pB = &dog;
	pB->speak();
	return 0;
}


/*
结果:
猫的叫声：喵喵
狗的叫声：汪汪
*/

/*
如果基类与派生类中有同名成员函数，根据类型兼容规则，当使用基类指针或基类引用操作派生类对象时，只能调用基类的同名函数。
如果想要使用基类指针或基类引用调用派生类中的成员函数，就需要虚函数解决，虚函数是实现多态的基础

虚函数
```
class 类名 
{ 
权限控制符： 
 virtual 函数返回值类型 函数名（参数列表）; 
 … //其他成员 
};
```

声明虚函数时，有以下3点需要注意：
1）构造函数不能声明为虚函数，但析构函数可以声明为虚函数。
2）虚函数不能是静态成员函数。
3）友元函数不能声明为虚函数，但虚函数可以作为另外一个类的友元函数。


注意：
派生类对基类虚函数重写时，必须与基类中虚函数的原型完全一致，派生类中重写的虚函数前是否添加virtual，均被视为虚函数。
*/