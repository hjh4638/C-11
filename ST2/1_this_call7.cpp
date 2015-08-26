#include <iostream>
using namespace std;
//다중 상속과 this
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
	
	ccc.fx();//100 예측해보세요 
	ccc.fy();//104

	void(C::*f)(); //8바이트입니다.
	//{함수구조, this offset}
	f = &C::fx; // f = {fx 주소, 0}
	(ccc.*f)();//결과? 100나와야한다.
	//f(&ccc)

	f = &C::fy; //f={fy주소, sizeof(X) 즉, 4}
	(ccc.*f)();// 결과? 104나와야한다.
	//f(&ccc)
	//f.함수구조(&ccc+f.this_offset)
	cout << sizeof(f) << endl;
}