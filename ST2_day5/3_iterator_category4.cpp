#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// STL ���� �ݺ����� 5�� ������ Ÿ��ȭ �մϴ�.
// empty class : �ƹ� ����� ���� ����ü(Ŭ����)
//				 ����� ��� Ÿ���� Ÿ���̴�!.
//				��κ�, �Լ� �����ε��̳� ���ø����ڷ� Ȱ��ȴ�.
/*
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag : input_iterator_tag{};
struct bidirectional_iterator_tag : forward_iterator_tag{};
struct random_access_iterator_tag : bidirectional_iterator_tag{};

// ��� �ݺ����� �����ڴ� �ڽ��� � �������� �ܺο� �˷��� �Ѵ�.
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

// �ݺ��ڴ� 2���� ���°� �ֽ��ϴ�.
// 1. ��¥ ������
// 2. ��ü�� ���� �ݺ���
// 2���� ���� ������ �Ϲ�ȭ �˰��� �ۼ��� ��ƽ��ϴ�.
// �Ʒ� ������ �ʿ��մϴ�.
//template<typename T> struct iterator_traits
//{
//	typedef T::iterator_category iterator_category;
//};
//template<typename T> struct iterator_traits<T*>
//{
//	typedef random_access_iterator_tag iterator_category;
//};
template<typename T>
void xadvance(T& p, int n) // n>0�� �����մϴ�.
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
	vector<int> v(x, x + 10); // x~x+10���� �ʱ�ȭ

	vector<int>::iterator p = v.begin();

	xadvance(p, 5); // p�� 5ĭ�̵�

	cout << *p << endl; // 6

}