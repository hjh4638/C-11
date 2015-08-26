int main()
{
	// 1. const 위치 - 아래 2줄은 완전히 동일합니다.
	// const int c1 = 10;
	// int const c1 = 10;

	// 2. 상수와 비상수를 가리키는 포인터
	int n = 10;
	const int* p1 = &n; // *를 기점으로 보고 
						// p1을 따라가면 const int가 있다.
						// ok..
						// 상수를 가르키는 포인터 = &비상수

	const int c = 10;
	int* p2 = &c; // error. 원본 자체가 Read only 인데
				  // 포인터를 통해서는 쓰리도 하겠다는 것!!

				  // 비상수를 가리키는 포인터 = &상수 는 안됨!
}