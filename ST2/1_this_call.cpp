#include <iostream>
using namespace std;

class Point{
	int x, y;
public:
	void set(int a, int b){//void set(Point* const this, int a, int b)
		x = a;
		y = b;
	}
};