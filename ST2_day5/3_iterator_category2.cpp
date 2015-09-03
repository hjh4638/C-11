
int main()
{
	// 우리가 만든 slist를 생각해 봅시다.

	slist<int> s;
	s.push_front(10);
	s.push_front(10);

	slist<int>::iterator p = s.begin();
	++p; // ok
	--p; // ?? 될까요 ? 문법적으로는 문제 없지만
		 // 싱글리스트라는 자료 구조 특성상 만들 수 없다.
}