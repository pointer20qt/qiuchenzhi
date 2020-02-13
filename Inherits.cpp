#include <iostream>
using namespace std;

class school{
public:
	string schoolName;
	string schollType;
	string address;
	school(string schoolName, string schoolType, string address){
		this->schoolName = schoolName;
		this->schollType = schoolType;
		this->address = address;
	}
	virtual ~school(){

	}
	void getschool()
	{

	}
	void getschool(int i)
	{
		cout << "学校开学了" << endl;
	}
};
class highschool :public school
{
public:
	highschool() :school("穆棱中学","高中","黑龙江")
	{

	}
	~highschool()
	{

	}
	//void getschool()
	//{
	//	cout << "高中开学了" << endl;
	//}
};

int main()
{
	school *s = new highschool;
	highschool *t = (highschool*)s;
	highschool u;
	u.getschool(2);

	t->getschool();
	highschool *hs = new highschool;
	school *sc = new school("xx大学","大学","xx");
	hs->getschool();
	sc->getschool(1);

	return 0;
}