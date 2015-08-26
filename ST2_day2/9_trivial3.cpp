#include <iostream>
using namespace std;

// trivial traits를 만드는 일반적인 기술은 어렵습니다.

// 안드로이드 framwork 에서는
template<typename T> struct has_trivial_ctor{enum {value = false};};

template<> struct has_trivial_ctor<int>{ enum { value = true }; };
template<> struct has_trivial_ctor<double>{ enum { value = true }; };

struct Point
{
	int x, y;
};
template<> struct has_trivial_ctor<Point>{ enum { value = true }; };

if (has_trivial_ctor<int>::value){

}