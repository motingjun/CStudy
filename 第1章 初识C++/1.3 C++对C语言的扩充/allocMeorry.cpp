#include<iostream>

using namespace std;

int main()
{
	int* pi = new int(10);		//创建一个int对象, 初始值为10
	cout<<"*pi="<<*pi<<endl;
	*pi = 20;					//通过指针改变内存中的值
	cout<<"*pi = "<<*pi<<endl;
	//创建一个大小为10的char类型数组
	char* pc = new char[10];
	for (int i = 0; i < 10; i++)
	pc[i] = i + 65;				//向数组中存入元素
	for (int i = 0; i < 10; i++)
	cout<<pc[i]<<" ";
	cout<<endl;
	delete pi;					//释放int对象
	delete []pc;				//释放char对象
	return 0;
}


/*
结果:
*pi=10
*pi = 20
A B C D E F G H I J
*/


/*
C++增加了new运算符分配堆内存，delete运算符释放堆内存。
如果内存申请成功，则new返回一个具体类型的指针；如果内存申请失败，则new返回NULL。

new申请内存空间的过程，通常称为new一个对象。与m alloc()相比，new创建动态对象时不必为对象命名，
直接指定数据类型即可，并且new能够根据初始化列表中的值进行初始化。
*/