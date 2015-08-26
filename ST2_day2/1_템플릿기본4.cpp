//지연된 인스턴스화(lazy instantiation)
//사용되지 않은 함수 (멤버함수) 템플릿은 인스턴스화(실제함수로) 되지 
//않는다.
//이 개념을 사용한 기법이 아주 많이 있습니다.

class aaa{
public:
	void foo(int a)
	{
		*a = 10;
	}
};

//template<typename T> class AAA
//{
//public:
//	void foo(T a)
//	{
//		*a = 10;
//	}
//};

int main(){
	AAA<int> aaa;
	//aaa.foo(0);
}