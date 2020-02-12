#include "deep_copy.h"
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
	school(const school& a){
		cout << "拷贝构造函数" << endl;
		stu = new student(*(a.stu));
	}
	~school(){
		delete stu;
	}

};

int main(){
	school s1("1", "1", "1");
	school s2((s1));
	return 0;


}