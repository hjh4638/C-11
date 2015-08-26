
// Sort( ... Less()) 등의 표현식 처럼. 임시객체를 인자로 보내려면
// 값 또는 const 참조 로 받아야 한다.
// const 참조의 함수객체를 사용하려면 ()연산자가 상수함수이어야 한다.

// 함수 객체를 만들 때 되도록이면 상수함수로 하자!!!
struct Less
{
	bool operator()(int a, int b) const{ return a < b; }
};

template<typename T>
void Sort(int* x, int n, const T& cmp)
{
	cmp(x[0],x[1]);
}

int main()
{
	int x[10] = { 0, };
//	Less f1;
//	Sort(x, 10, f1);

	Sort(x, 10, Less()); // 만들면서 인자로 전달 - 임시객체
}