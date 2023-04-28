#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Student
{
private:
	string _id;
	char* _name;
public:
	Student(string id, const char* name):_id(id)
	{
		_name = new char[strlen(name)+1];
		strcpy(_name,name);
	}

	operator char*()	//类型转换运算符重载函数
	{
		return _name;
	}
	void show()
	{
		cout<<"ID:"<<_id<<","<<"name:"<<_name<<endl;
	}	
};


int main()
{
	Student s1("1001","小明");	//调用普通构造函数创建对象
	cout<<"s1: ";
	s1.show();
	char* ch = s1;	//调用类型转换函数
	cout<<ch<<endl;
	return 0;
}


/*
结果:
s1: ID:1001,name:小明
小明
*/


/*
类型转换函数也称为类型转换运算符重载函数，定义格式如下所示：
```
operator 数据类型名() 
{ 
 ...//函数体 
} 
```

类型转换函数以operator关键字开头，这一点和运算符重载规律一致。
从类型转换函数格式可以看出，在重载的数据类型名前不能指定返回值类型，
返回值的类型由重载的数据类型名确定，且函数没有参数。
由于类型转换函数的主体是本类的对象，因此只能将类型转换函数重载为类的成员函数。
*/