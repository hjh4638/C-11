#include <vector>
using namespace std;
template<typename T> class MyAlloc{};

// 복잡한 타입은 typedef 먼저 만드는 것이 좋다.
typedef void(*PF)();

//typedef vector<int, MyAlloc<int>> MyVector;

// 아래 코드 처럼 사용하고 싶을 때가 많다.!
template<typename T> typedef vector<T>, MyAlloc<T>> MyVector;

// C++11의 using 은 template이 된다.
// "template alias" 또는 "template typedef" 라는 이름을 가진 문법
template<typename T>
using MyVector = vector < T, MyAlloc<T> > ;

// C++11
using PF = void(*)();

int main()
{
	//void(*f)();
	PF f;
	MyVector<int> v;
}