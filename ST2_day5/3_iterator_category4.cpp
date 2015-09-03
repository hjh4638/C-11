#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// STL 에는 반복자의 5개 개념을 타입화 합니다.
// empty class : 아무 멤버도 없는 구조체(클래스)
//				 멤버가 없어도 타입은 타입이다!.
//				대부분, 함수 오버로딩이나 템플릿인자로 활용된다.
/*
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag : input_iterator_tag{};
struct bidirectional_iterator_tag : forward_iterator_tag{};
struct random_access_iterator_tag : bidirectional_iterator_tag{};

// 모든 반복자의 설계자는 자신이 어떤 종류인지 외부에 알려야 한다.
template<typename T> class vector_iterator
{
public:
typedef random_access_iterator_tag iterator_category;
//.....
};
template<typename T> class list_iterator
{
public:
typedef bidirectional_iterator_tag iterator_category;
//.....
};
*/

// 반복자는 2가지 형태가 있습니다.
// 1. 진짜 포인터
// 2. 객체로 만든 반복자
// 2가지 형태 때문에 일반화 알고리즘 작성이 어렵습니다.
// 아래 도구가 필요합니다.
//template<typename T> struct iterator_traits
//{
//	typedef T::iterator_category iterator_category;
//};
//template<typename T> struct iterator_traits<T*>
//{
//	typedef random_access_iterator_tag iterator_category;
//};
template<typename T>
void xadvance(T& p, int n) // n>0만 생각합니다.
{
	xadvanceImp(p, n, typename iterator_traits<T>::iterator_category());
}
template<typename T>
void xadvanceImp(T& p, int n, random_access_iterator_tag)
{
	p = p + n;
}
template<typename T>
void xadvanceImp(T& p, int n, input_iterator_tag)
{
	while (n--)++p;
}

int main()
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* p2 = x;
	xadvance(p2, 5);
	vector<int> v(x, x + 10); // x~x+10으로 초기화

	vector<int>::iterator p = v.begin();

	xadvance(p, 5); // p를 5칸이동

	cout << *p << endl; // 6

}