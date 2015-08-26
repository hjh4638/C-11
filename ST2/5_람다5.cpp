#include <iostream>
#include <algorithm>
using namespace std;

bool cmp1(int a, int b){ return a < b; }
bool cmp2(int a, int b){ return a > b; }

int main(){
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	//sort의 모든 인자는 템플릿 입니다.
	//1. 비교정책으로 일반 함수를 사용하는 경우
	//장점 : 정책을 여러번 교체해도 sort()기계어는 한개이다.
	//		 메모리 사용량 감소
	//단점 : 정책이 인라인 치환될 수 없기 때문에 성능저하가 있다.
	sort(x, x + 10, cmp1); //sort(int*,int*,bool(*)(int,int))함수 생성
	sort(x, x + 10, cmp1); //sort(int*,int*,bool(*)(int,int))함수 생성

	//2. 비교 정책으로 함수객체를 사용하는 경우
	//장점 : 정책이 인라인 치환 되므로 속도가 빠르다.
	//단점 : 정책을 교체한 횟수 만큼의 sort()함수 생성..
	//		 코드 메모리 증가
	less    f1;
	greater f2;
	sort(x, x + 10, f1); //sort(int*, int*, less) 함수 생성
	sort(x, x + 10, f2); //sort(int*, int*, greater) 함수 생성

	//3. C++11/14 람다 표현식(lambda expression)
	//함수 인자로 함수의 구현(코드)를 전달하는 기술
	//[] : Lambda introducer
	sort(x, x + 10, [](int a, int b){return a < b; });
}