#include <iostream>
using namespace std;
//���� ��Ӱ� this
class X{ 
public: int x; 
		void fx(){
			cout << this << endl;
		}
};
class Y{ 
public:int y; 
	   void fy(){ cout << this << endl; }
};

class C : public X, public Y{ public: int c; };

int main(){
	C ccc;
	cout << &ccc << endl;
	
	ccc.fx();//100 �����غ����� 
	ccc.fy();//104

	void(C::*f)(); //8����Ʈ�Դϴ�.
	//{�Լ�����, this offset}
	f = &C::fx; // f = {fx �ּ�, 0}
	(ccc.*f)();//���? 100���;��Ѵ�.
	//f(&ccc)

	f = &C::fy; //f={fy�ּ�, sizeof(X) ��, 4}
	(ccc.*f)();// ���? 104���;��Ѵ�.
	//f(&ccc)
	//f.�Լ�����(&ccc+f.this_offset)
	cout << sizeof(f) << endl;
}