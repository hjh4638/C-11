#include <iostream>
using namespace std;

int main(){
	//auto f1 = [](){cout << "f1" << endl; };

	//인자가 없는 람다는 ()의 생략이 가능하다.
	//Nullary Lamda expression
	auto f1 = []{cout << "f1" << endl; };

	f1();
}