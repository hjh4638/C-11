
// lvalue : = 의 양쪽에 모두 올 수 있다.
//			변수, 이름이 있다. 참조를 리턴하는 함수
//			블럭을 벗어날때 까지 생존
// rvalue : = 의 오른쪽에만 올 수 있다.
//			상수, 이름이 없다. 값을 리턴하는 함수, 임시객체
//			한문장안에서만 생존

int x = 10;
int foo() { return x; }
int& goo(){ return x; }

int main()
{
	int n1 = 10;
	int n2 = 20;

	n1 = 10;
	10 = n1; // error. 10은 rvalue 이다

	n2 = n1;

	foo() = 20; // error. 값을 리턴하는 함수, 임시객체생성, rvalue
	goo() = 20; // 
}