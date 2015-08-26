// 5_람다4
// 왜 함수 객체를 사용하는가? - 아주 중요합니다.

//1. 일반함수는 자신만의 타입이 없다 - 반드시 이해해야합니다.
//	  signature가 동일한 함수는 같은 타입이다.

//2. 함수 객체는 자신만의 타입이 있다.
//	 signature가 동일해도 모든 함수객체는 다른 타입이다.
#include <iostream>
using namespace std;
struct lesss{
	inline bool operator()(int a, int b){ return a < b; }
};
struct greater{
	inline bool operator()(int a, int b){ return a > b; }
};
//아래 함수는 cmp()가 인라인 치환되지만 greater로 교체할 수 없다.
//void Sort(int* x, int n, lesss cmp){

//정책교체가 가능하고 정책이 인라인 치환되는 함수
//"템플릿 + 함수객체"를 사용한 기술
template<typename T>
void Sort(int* x, int n, T cmp){
	for (int i = 0; i < n - 1; i++){
		for (int j = 1 + 1; j < n; j++){
			//if (x[i]>x[j]){
			if (cmp(x[i], x[j])){//인라인 치환 가능.
				swap(x[i], x[j]);
			}
		}
	}
}
lesss f1; Sort(x, 10, f1);
greater f2; Sort(x, 10, f2);