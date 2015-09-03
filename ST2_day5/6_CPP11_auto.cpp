int main()
{
	const int c = 10;
	const int& r = 10;
	int n = 10;
	int* p = &n;

	// auto 추론 : 템플릿과 동일
	// 규칙 1. auto n = 표현식 일때;
	//		표현식의 참조, const, volatile을 제거한다.

	auto a1 = r; // int

	// 규칙 2. auto& n = 표현식 일때
	//			표현식의 참조 속성만 제거한다.
	
	auto& a2 = r; // auto : int const		a2 : const int&

	// decltype은 정확한 타입으로 추론된다.
	decltype(r) n1 = c;
}