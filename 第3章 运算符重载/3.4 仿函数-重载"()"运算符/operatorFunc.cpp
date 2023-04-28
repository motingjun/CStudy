#include <iostream>
#include <string>

using namespace std;

class Show
{
public:
	void operator()(const string str)	//"()"运算符重载函数
	{
		cout<<str<<endl;
	}
	float operator()(const float num)	//"()"运算符重载函数
	{
		return num*num;
	}
};


int main()
{
	Show s;
	s("abcdef");
	cout<<s(4)<<endl;
	return 0;
}


/*
结果:
abcdef
16
*/

/*
仿函数指的是在类中重载“()”运算符后，这个类的对象可以像函数一样使用。
仿函数在STL的算法中使用比较广泛。此外，熟悉的lambda表达式在实现过程中也使用了仿函数。
*/