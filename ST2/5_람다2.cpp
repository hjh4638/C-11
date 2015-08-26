// 2. 정책 변경이 가능한 함수 만들기
#include <algorithm>
using namespace std;

// S/W설계의 기본 원칙 : 변하지 않은 전체 알고리즘에서
//						변해야 하는 부분을 찾아서 분리 한다.

//일반 함수는 변하는 부분을 함수 인자화 한다.(함수 포인터)
//C 표준 함수인 qsort()가 아래 모양입니다.
//핵심은 "알고리즘과 정책의 분리" 입니다.

//장점 : 함수가 사용하는 정책을 사용자가 변경할 수 있다.
//단점 : 결국 callback 함수를 사용하게 되므로 느리다.!!
//		 정책 함수를 인라인으로 만들어도 인라인치환 될 수 없다.
void Sort(int* x, int n, bool(*cmp)(int,int)){
	for (int i = 0; i < n - 1; i++){
		for (int j = 1 + 1; j < n; j++){
			//if (x[i]>x[j]){
			if (cmp(x[i], x[j])){
				swap(x[i], x[j]);
			}
		}
	}
}
// Sort() 사용자는 비교 함수를 전달해야 한다.
bool cmp1(int a, int b){ return a < b; }
bool cmp2(int a, int b){ return a > b; }
int main(){
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}


