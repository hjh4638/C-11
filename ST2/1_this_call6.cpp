#include <iostream>
using namespace std;

class X{ public: int x; };
class Y{ public:int y; };

class C : public X, public Y{ public: int c; };

int main(){
	C ccc;
	cout << &ccc << endl;

	X* pX = &ccc;
	Y* pY = &ccc;

	cout << pX << endl;
	cout << pY << endl;
}