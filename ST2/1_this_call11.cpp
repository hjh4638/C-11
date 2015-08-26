#include <iostream>
using namespace std;

//모든 함수의 주소를 담을 수 있는 도구
// C, C++ : 문법적으로는 없다.
//C++11:function<> 모든 함수의 주소를 담을 수 있다.

class Dialog
{
public:
	void Close()
	{
		cout << "Dialog Closed" << endl;
	}
};

void foo(){ cout << "foo" << endl; }
void goo(int a) { cout << "goo : " << a << endl; }
void hoo(int a, int b){ cout << "hoo : " << a << b << endl; }
void koo(int a, int b, int c, int d){
	printf("%d %d %d %d\n", a, b, c, d);
}
#include <functional>
using namespace std::placeholders;
int main(){
	function<void(int)> f = &goo;
	f(5); // goo(5)

	f = bind(&hoo,_1,3);

	f(5); //hoo(5, 3);

	function<void(int, int)>f2;
	f2 = bind(&koo, _2,2,9,_1 );//채우세요
	f2(6, 3);//3,2,9,6이 나오게 해주세요.
}