#include <iostream>
using namespace std;

//template meta programming : 컴파일 시에 연산을 수행하는 것

//컴파일 시간 재귀를 활용한다.
//재귀의 종류를 위해서 전문화 문법이 활용된다.
//메타 함수라고 부른다!!!!

//template 인자로 타입이 아닌 정수를 보내도 됩니다.
template<int N> struct Factorial
{
	enum{value = N* Factorial<N-1>::value};
};
template<> struct Factorial < 1 >
{
	enum{value=1};
};
int main()
{
	int n = Factorial<5>::value; //잘 생각해 보세요!!!
			//5*F<4>::v
			//5*F<4>::v
	cout << n << endl;

	int a = 5; cin >> a;
	int n2 = Factorial<a>::value; //error. 템플릿 인자는
									//컴파일 시간 상수만 가능!!

	//과제 1. binary<> 만들어보세요
	int n3 = binary<101>::value;
	
	cout << n3 << endl;


	//과제 2. 아래 코드가 컴파일 에러 나오게 해보세요
	int n4 = binary<201>::value;
	
}

//어제 숙제와 함께
//smkang@ioacademy.co.kr로 보내주세요..
//기한은 없으니.. 다하신분은 보내 주세요..