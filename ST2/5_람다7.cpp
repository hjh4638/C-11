#include <iostream>
using namespace std;

//람다와 타입
int main(){
	// 람다는 auto에 담을수 있습니다.
	auto f1 = [](int a, int b){return a + b; };
	auto f2 = [](int a, int b){return a + b; };
	
	//f1과 f2는 같은 타입일까요? 다른 타입일까요?

	//RTTI 기술로 컴파일러가 만들어준 함수객체 클래스의 이름도 확인가능합니다.
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

	cout << f1(1, 2) << endl;
}