class AAA{
public:
	//....
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

//템플릿안에 있는 타입을 꺼낼때는 반드시 typename을 적어야 합니다.

typename T::DWORD a;

//템플릿이 아닐때는 사용하면 안됩니다.
typename AAA::DWORD a;//error. AAA는 템플릿이 아니고 일반 타입!

template<typename T> void foo(T a)
{
	typename T::DWORD *p; //이 한줄을 해석해 보세요
				//1. DWORD는 static 멤버 data이다.
				//곱하기 p를 하고 있다
				//2. DWORD는 typedef등으로 만든 타입니다.
				// 포인터 변수 p를 선언하고 있다
}
int main(){
	AAA aaa;
	foo(aaa);
}