// 1.간접층의 원리

// 아무리 어려운 S/W 문제점도 중간층(기존 요소 사이에 새로운 요소)
// 를 도입하면 해결할 수 있다.
// "Level Of Indirection" 이라는 원리

// 기존요소를 대신한다는 의미로 "Proxy" 패턴이라고도 부르는 디자인기법
struct VectorSize
{
	int size;
	VectorSize(int n) // int => VectorSize로 암시적 변환된다.
		: size(n){}
};

class Vector
{
public:
	//Vector(int sz){}
	Vector(VectorSize sz){ // VectorSize => Vector로 암시적 변환된다.
		int size = sz.size;
	}
};

void foo(Vector v){}

int main()
{
	Vector v(10);
	foo(v); // ok



	foo(20); // ???? int => Vector 즉, 변환생성자가 있으면 OK..
}