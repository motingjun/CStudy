#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout<<setw(10)<<3.1415<<endl;
	cout<<setw(10)<<setfill('0')<<3.1415<<endl;
	cout<<setw(10)<<setfill('0')<<setiosflags(ios::left)<<3.1415<<endl;
	cout<<setw(10)<<setfill('-')<<setiosflags(ios::left)<<3.1415<<endl;
	return 0;
}

/*
C++提供了setw()函数用于指定域宽，setiosflags()函数用于设置对齐方式，setfill()函数用于设置填充方式。
*/

/*
结果:
    3.1415
00003.1415
3.14150000
3.1415----
*/