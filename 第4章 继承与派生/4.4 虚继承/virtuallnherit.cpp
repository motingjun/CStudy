#include <iostream>

using namespace std;

class Furniture    //家具类Furniture
{
public:
	Furniture(string wood);
protected:
	string _wood;	//成员变量_wood,表示材质
};

Furniture::Furniture(string wood)
{
	_wood = wood;
}


class Sofa:virtual public Furniture    //沙发类Sofa，虚继承Furniture类
{
public:
	Sofa(float length, string wood);
protected:
	float _length;	//成员变量_length, 表示沙发长度
};

Sofa::Sofa(float length, string wood):Furniture(wood)
{
	_length = length;
}


class Bed:virtual public Furniture    //床类Bed，虚继承Furniture类
{
public:
	Bed(float width, string wood);
protected:
	float _width;
};

Bed::Bed(float width, string wood):Furniture(wood)
{
	_width = width;
}


class Sofabed:public Sofa, public Bed
{
public:
	Sofabed(float length, string wood1, float width, string wood2);
	void getSize();
};

Sofabed::Sofabed(float length, string wood1, float width, string wood2):
	Sofa(length, wood1), Bed(width, wood2), Furniture(wood1)
{

}

void Sofabed::getSize()
{
	cout<<"沙发床长"<<_length<<"米"<<endl;
	cout<<"沙发床宽"<<_width<<"米"<<endl;
	cout<<"沙发床材质为"<<_wood<<endl;
}


int main()
{
	Sofabed sbed(1.8, "梨木", 1.5, "檀木");
	sbed.getSize();
	return 0;
}


/*
结果：
沙发床长1.8米
沙发床宽1.5米
沙发床材质为梨木
*/

/*
在程序设计过程中，通常希望间接基类的成员变量在底层派生类中只有一份拷贝，从而避免成员访问的二义性。
通过虚继承可以达到这样的目的，虚继承就是在派生类继承基类时，在权限控制符前加上virtual关键字，其格式如下所示：
```
class 派生类名：virtual 权限控制符 基类名 
{ 
 派生类成员 
}; 
```

在上述格式中，在权限控制符前面添加了virtual关键字，就表明派生类虚继承了基类。被虚继承的基类通常称为虚基类，
虚基类只是针对虚继承，而不是针对基类本身。在普通继承中，该基类并不称为虚基类。
*/