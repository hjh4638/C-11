#include <algorithm>
using namespace std;

int main(){
	int x[10];

	sort(x, x + 10, [](int a, int b){return a < b; });
	
	//위 한줄을 보고 컴파일러는 아래 코드를 생성합니다.

	class closure_object{
	public:
		// 함수 객체의 핵심 () 연산자
		inline bool operator()(int a, int b) const{
			return a < b;
		}
	};
	closure_object f;
	sort(x, x + 10, f);

	//정확히는 임시 객체로 전달합니다.
	sort(x, x + 10, closure_object());
}