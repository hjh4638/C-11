#include <iostream>
using namespace std;

// trivial traits�� ����� �Ϲ����� ����� ��ƽ��ϴ�.

// �ȵ���̵� framwork ������
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