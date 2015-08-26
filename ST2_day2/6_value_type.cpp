#include <iostream>
#include <vector>
#include <list>
using namespace std;

//void print(vector<int>& v)
//{
//	int n = v.front();
//	cout << n << endl;
//}
//
//template<typename T> void print(vector<T>& v)
//{
//	? n = v.front();
//	cout << n << endl;
//}
//template<typename T>
//void print(T& v)
//{
//	//T:            => list<double>
//	//T::value_type => double
//	typename T::value_type n = v.front();
//	cout << n << endl;
//}
template<typename T>
void print(T& v)
{
	//T:            => list<double>
	//T::value_type => double
	auto n = v.front();
	cout << n << endl;
}
int mian()
{
	list<double> v(10.1, 3);
	print(v);
}

// ��� template ��� �����̳ʿ��� �����ϴ� Ÿ���� �ֽ��ϴ�.
// �׷��� �� Ÿ���� �ܺο��� (���� print) �˰� ���� ���� �ֽ��ϴ�.
// �׷���, �Ʒ� ó�� ����� �˴ϴ�.
template<typename T> class list
{
public:
	typedef T value_type;
	//.....
};

list<int>::value_type n; //�ᱹ n�� _int_ Ÿ���Դϴ�.