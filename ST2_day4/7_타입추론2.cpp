// ��Ģ 2. ParamType�� �����ͳ� ���� �϶�
// - expr �� ���۷������ ���۷����� ���õȴ�! const�� �����ȴ�.
// - expr �� ����ؼ� Ÿ���� �����Ѵ�.
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