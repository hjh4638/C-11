// 스마트 포인터가 참조계수를 관리하는 2가지 방식

// 1. 참조계수를 위한 별도의 메모리 할당
// shared_ptr<> : C++ 표준, 모든 타입에 대해 사용가능

shared_ptr<int> p(new int); // 모든 타입에 대해 사용가능

// 2. 객체 내부에 참조계수를 포함
//	C++ 표준이 아니라
//	각 라이브러리가 자체적으로 제공하는 기술들
//	(안드로이드 RefBase, sp)
//	( Poco, )
sp<int> p = new int; // 안됨. error. sp를 사용하려면 RefBase
					// 자신만 된다.

// www.pocoproject.com

// \poco -1.6.1\poco1.6.1\Foundation\include\Poco

// 다양한 헤더 중에서 참조계수를 책임지는 클래스가 있는 헤더를
// 찾아보세요.