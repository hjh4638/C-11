#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b){ cout << "int, int" << endl; }
	Point(initializer_list<int> e){ cout << "initializerList" << endl; }
};

int main()
{
	Point p1(1, 2); // int, int
	Point p11({ 1, 2 }); // initializerList
	Point p2{ 1, 2 }; // initializerList - 핵심!
					  // 없다면 int, int 호출
	//Point p3(1, 2, 3); // error
	Point p4{ 1, 2, 3 }; // 

	Point p6 = { 1, 2 }; // ok

	// 1 ~ 10 까지로 초기화된 vector 만들기
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
}