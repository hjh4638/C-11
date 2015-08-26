int main()
{
	int n = 10;
	
	// 어느 메모리가 상수인가 ?
	//const int* p1 = &n; // p1을 따라가면 const가 있다
	int* const p2 = &n; // p2를 따라가면 const가 아니다
						// 하지만, p2 자체가 const이다.
						// 초기화는 가능
	p2 = &n2; // error
	*p2 = 20; // ok

	// 아래 2줄은 동일
	int const* p3 = &n; // p1와 동일
	const int* p1 = &n;
}

// this의 상수성
class Point
{
	int x, y;
public:
	void Set() // void Set( Point* const this )
	{
		x = 0; // this->x = 0;
		y = 0; // this->y = 0;

		this = 0;// error. this 포인터 자체는 상수이다.
		x = 0;
	}

	void print() const // void print( const Point* const this )
	{
		x = 0; // this->x = 10;
	}
}