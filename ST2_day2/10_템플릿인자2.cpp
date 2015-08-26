
// 3. template 인자로 template을 보낼 수 있다.
template<typename T> class list
{
};

//여기서 앞에 class는 typename로 대체 불가
template<typename T, template<typename> class C> class stack
{
	//C c; // error. C는 template 이다
	C<T> c; // ok.
};

int main()
{
	list str1; // error, list는 template이다.
	list<int> str2; // ok. list<int>는 type이다.

	stack<int, list> s;
}