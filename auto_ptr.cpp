#include<iostream>
#include<memory>
using namespace std;

template<class T>
class autoptr{
	T* obj = nullptr;
public:
	autoptr(T* ptr) :obj(ptr){

	}
	autoptr() = default;
	~autoptr(){
		delete obj;
	}
	autoptr(autoptr<T>&ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	autoptr& operator=(autoptr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newPtr){
		delete obj;
		obj = newPtr;
	}
	T* release()
	{
		auto tmp = obj;
		obj = nullptr;
		return tmp;
	}
	T& operator*(){
		return *obj;
	}
	T* operator->(){
		return obj;
	}
};

class L
{
public:
	int val;
	L(int val){
		this->val = val;
	}

};
int main(){
	L* life = new L(7);
	autoptr<L>lautoptr(life);
	cout << lautoptr->val << endl;
	L* life1 = new L(10);
	autoptr<L>ptr2(life1);
	autoptr<L>ptr3;
	ptr3 = ptr2;
	ptr3.reset(new L(19));
	cout << ptr3->val << endl;
	ptr3.release();

}