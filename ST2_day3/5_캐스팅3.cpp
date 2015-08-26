#include <iostream>
using namespace std;

class X{ public: int x; };
class Y{ public: int y; };

class C : public X, public Y{};

int main()
{
	C c;
	cout << &c << endl; //100번지 라고 할때

	//Y* py = &c; // 104번지
	//Y* py = (Y*) &c;
	
	//Y* py = static_cast<Y*>(&c); // 104
									// &c 메모리에서 Y를 찾아라
									// 없다면 error
									// 실행시간이 아닌 
									// 컴파일 시간에!!!
	Y* py = reinterpret_cast<Y*>(&c); // &c 주소를 무조건 Y*로
									// 생각하겠다는것!!
									// C와 Y의 연관성은
									// 전혀 고려하지 않음

	py->y = 10; // c의 입장에서는 어디에 놓일까요?
	
	cout << c.x << endl; // 10

	cout << py << endl; // ??
}