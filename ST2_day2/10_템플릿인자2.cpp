
// 3. template ���ڷ� template�� ���� �� �ִ�.
template<typename T> class list
{
};

//���⼭ �տ� class�� typename�� ��ü �Ұ�
template<typename T, template<typename> class C> class stack
{
	//C c; // error. C�� template �̴�
	C<T> c; // ok.
};

int main()
{
	list str1; // error, list�� template�̴�.
	list<int> str2; // ok. list<int>�� type�̴�.

	stack<int, list> s;
}