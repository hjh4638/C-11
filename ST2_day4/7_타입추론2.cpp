// 규칙 2. ParamType이 포인터나 참조 일때
// - expr 이 레퍼런스라면 레퍼런스만 무시된다! const는 유지된다.
// - expr 을 고려해서 타입을 결정한다.
template<typename T> void foo(T& a)			{}
template<typename T> void goo(const T& a)	{}

int main()
{
	int n = 10;
	const int c = n;
	const int& r = c;

	foo(n); // T : int				a : int&
	foo(c); // T : const int		a : const int&
	foo(r); // T : const int		a : const int&

	goo(n); // T : int				a : const int&
	goo(c); // T : int				a : const int&
	goo(r); // T : int				a : cosnt int&
}