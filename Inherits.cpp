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
		cout << "ѧУ��ѧ��" << endl;
	}
};
class highschool :public school
{
public:
	highschool() :school("������ѧ","����","������")
	{

	}
	~highschool()
	{

	}
	//void getschool()
	//{
	//	cout << "���п�ѧ��" << endl;
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
	school *sc = new school("xx��ѧ","��ѧ","xx");
	hs->getschool();
	sc->getschool(1);

	return 0;
}