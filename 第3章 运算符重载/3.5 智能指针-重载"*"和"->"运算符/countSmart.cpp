#include <iostream>
#include <string>

using namespace std;

class Data
{
public:
	Data(string str):_str(str)
	{
		cout<<"Data类构造函数"<<endl;
	}
	~Data()
	{
		cout<<"Data类析构函数"<<endl;
	}
	void dis()
	{
		cout<<_str<<endl;
	}
private:
	string _str;
};


class Count 	//Count类用于存储指向同一资源的指针数量
{
public:
	friend class SmartPtr;
	Count(Data *pdata):_pdata(pdata),_count(1)
	{
		cout<<"Count类构造函数"<<endl;
	}
	~Count()
	{
		cout<<"Count类析构函数"<<endl;
		delete _pdata;
	}
private:
	Data *_pdata;
	int _count;
};

//使用指针实现智能指针
class SmartPtr  	//SmartPtr类用于对指向Data类对象的指针实现智能管理
{
public:
	SmartPtr(Data* pdata):_reNum(new Count(pdata))
	{
		cout<<"创建基类对象"<<endl;
	}
	SmartPtr(const SmartPtr& another):_reNum(another._reNum)
	{
		++_reNum->_count;
		cout<<"SmartPtr类复制构造函数"<<endl;
	}
	~SmartPtr()
	{
		if (--_reNum->_count==0)
		{
			delete _reNum;
			cout<<"SmartPtr类析构函数"<<endl;
		}
	}
	Data *operator->()
	{
		return _reNum->_pdata;
	}
	Data &operator*()
	{
		return *_reNum->_pdata;
	}
	int disCount()
	{
		return _reNum->_count;
	}
private:
	Count *_reNum;
};


int main()
{
	Data *pstr1 = new Data("I Love China!");
	SmartPtr pstr2 = pstr1;
	(*pstr1).dis();
	SmartPtr pstr3 = pstr2;
	pstr2->dis();
	cout<<"使用基类对象的指针数量："<<pstr2.disCount()<<endl;
	return 0;
}


/*
结果:
Data类构造函数
Count类构造函数
创建基类对象
I Love China!
SmartPtr类复制构造函数
I Love China!
使用基类对象的指针数量：2
Count类析构函数
Data类析构函数
SmartPtr类析构函数
*/

//当引用计数为零时自动释放资源，使用引用计数可以跟踪堆中对象的分配和自动释放堆内存资源。