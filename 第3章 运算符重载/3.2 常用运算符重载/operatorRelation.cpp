#include <iostream>

using namespace std;

class Student
{
private:
	int _id;
	double _score;
public:
	Student(int id, double score):_id(id),_score(score){}
	
	void dis()
	{
		cout<<"学号"<<_id<<"成绩"<<_score<<endl;
	}
	//重载关系运算符
	friend bool operator==(const Student& st1, const Student& st2);
	friend bool operator!=(const Student& st1, const Student& st2);
	friend bool operator>(const Student& st1, const Student& st2);
	friend bool operator<(const Student& st1, const Student& st2);
};

bool operator==(const Student& st1, const Student& st2)
{
	return st1._score==st2._score;		//重载"=="运算符
}

bool operator!=(const Student& st1, const Student& st2)
{
	return !(st1._score==st2._score);	//重载"!="运算符
}

bool operator>(const Student& st1, const Student& st2)
{
	return st1._score>st2._score;		//重载">"运算符
}

bool operator<(const Student& st1, const Student& st2)
{
	return st1._score<st2._score;		//重载"<"运算符
}


int main()
{
	Student st1(1001,96), st2(1002,105);
	cout<<"比较两名学生的成绩: "<<endl;
	if (st1>st2)
		st1.dis();
	else if(st1<st2)
		st2.dis();
	else
		cout<<"两名学生成绩相同: "<<endl;
	return 0;
}


/*
结果：
比较两名学生的成绩: 
学号1002成绩105
*/

//关系运算符重载