#include<iostream> 

using namespace std;
 
class Person     //定义类Person
{ 
public: 
     Person(string name,int age,string addr);  //声明有参构造函数
     ~Person();                                //声明析构函数
     const string _addr;                       //声明表示住址的常成员变量
private: 
     const string _name;    //声明表示姓名的常成员变量
     const int _age;        //声明表示年龄的常成员变量
};

//类外实现构造函数 
Person::Person(string name,int age,string addr): 
     _name(name),_age(age),_addr(addr)
{
     cout<<"初始化const修饰的成员变量"<<endl;
     cout<<"name:"<<_name<<endl;
     cout<<"age:"<<_age<<endl;
     cout<<"addr:"<<_addr<<endl;
}

Person::~Person(){}    //类外实现析构函数

int main() 
{
     Person p1("张三",18,"北大街");
     p1._addr="南大街";    //因修改常变量导致编译报错
     return 0; 
}


/*
const 修饰成员变量

使用const修饰的成员变量称为常成员变量。对于常成员变量，仅仅可以读取第一次初始化的数据，之后是不能修改的。常成员变量通常使用有参构造函数进行初始化。
*/