#include<iostream>

using namespace std;

void exchange(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a, b;
	cout << "please input two nums: " << endl;
	cin >> a >> b;
	exchange(a, b);
	cout << "exchange: " << a << " " << b << endl;
	return 0;
}


/*
结果:
please input two nums: 
2 3
exchange: 3 2
*/


/*
在C++中，引用的一个重要作用是作为函数参数。
引用是隐式的指针，但引用却不等同于指针，使用引用与使用指针有着本质的区别。
1）指针指向一个变量，需要占据额外的内存单元，而引用指向一个变量，不占据额外内存单元。
2）作为函数参数时，指针的实参是变量的地址，而引用的实参是变量本身，但系统向引用传递的是变量的地址而不是变量的值。

如果想使用常量值初始化引用，则引用必须用const修饰，用const修饰的引用称为const引用，也称为常引用。
const int &a = 10; 
const int b = 10;    
const int &rb = b;

常变量的引用必须是const引用，但const引用不是必须使用常量或常变量进行初始化，const引用可以使用普通变量进行初始化，
只是使用普通变量初始化const引用时，不允许通过该引用修改变量的值。
int a = 10;          //变量a 
const int &b = a;    //使用a初始化const引用b 
b=20;                //错误
*/