#include <iostream>
#include <functional>
using namespace std;

int main(){
	//람다는 3가지 형태 변수에 담을 수 있습니다.
	auto f1 = [](int a, int b){return a + b; };

	int(*f2)(int, int) = [](int a, int b){return a + b; };

	function<int(int, int)> f3 = [](int a, int b){return a + b; };

	f1(1, 2); // 인라인 치환 된다.
	f2(1, 2); // 인라인 치환 안된다.
	f3(1, 2); // 인라인 치환 안된다.

	//람다와 함수 인자
	foo([](int a, int b){return a + b; });
}

//람다를 인자로 받는 방법 - 아래 2개는 가능하지만 인라인 치환 안됨
void foo(int(*f2)(int, int)){}//ok
void foo(function<int(int,int)>f3){}//ok

//auto는 함수 인자가 될 수 없다.!!
void foo(auto f1){} //foo(1)   => int
					//foo(3.4) => double

//인라인 치환 가능하게 람다를 받는 유일한 방법 - template
template<typename T> void foo(T f){
	f(1, 2);
}