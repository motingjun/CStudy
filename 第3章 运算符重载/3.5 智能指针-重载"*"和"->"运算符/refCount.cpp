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


int main()
{
	Data *pstr1 = new Data("I Love China");
	Data *pstr2 = pstr1;
	Data *pstr3 = pstr1;
	pstr1->dis();
	delete pstr1;
	pstr2->dis();
	return 0;
}