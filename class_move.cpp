#include "class_move.h"
#include<iostream>
#include<string>
using namespace std;

class student{
	string name;

public:
	student(string name){
		this->name = name;
	}
	~student(){
		cout << "判断析构函数是否执行" << endl;
	}

};

class school{
public:
	string schoolName;
	string schollType;
	string address;
	student *stu;
	school(string schoolName, string schoolType, string address){
		this->schoolName = schoolName;
		this->schollType = schollType;
		this->address = address;
		this->stu = new student("111");
	}
	school(school &&a)
	{
		cout << "移动构造函数" << endl;
		stu = a.stu;
		a.stu = NULL;
	}

	~school(){
		delete stu;
	}

};
int main()
{
	school s1("12","23","34");
	school s2(move(s1));
	using  I = int;
	I a = 1;
	I b = 2;
	I c = a + b;
	cout << c << endl;
	return 0;
}