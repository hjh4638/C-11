class Base
{
public:
	virtual void foo(int){}
	virtual void goo() const{}
	void hoo(){}
};

class Derived : public Base
{
public:
	// 가상함수를 재정의 하고 싶었습니다. 그런데
	// 다음 중 개발자의 실수를 모두 고르세요
	/*
	void foo(int){}					//1 ok virtual 생략가능
	virtual void foo(double){}		//2 파라미터 타입 틀렸다
	virtual void goo(){}			//3 상수 함수가 아니다
	virtual void gooo(){}			//4 함수 이름 틀렸다
	void hoo(){}					//5 가상함수가 아니다
	*/
	void foo(int) override{}				//1 ok virtual 생략가능
	virtual void foo(double) override{}		//2 파라미터 타입 틀렸다
	virtual void goo() override{}			//3 상수 함수가 아니다
	virtual void gooo() override{}			//4 함수 이름 틀렸다
	void hoo()override{}					//5 가상함수가 아니다

	virtual void foo(int) final{}
	// Derived 의 자식 클래스 부터는 foo를 재정의 할 수 없다.
};

int main()
{

}