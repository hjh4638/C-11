//template<typename T> void foo(T a, T b)
template<typename T> void foo(T& a, T& b)
{
}

//T&로 만들때 문자열을 보낼때 혼란스러워 질 수 있다.
//이경우는 문자열 전용 버전을 만들면 된다.
//함수 찾는 순서
//1. 정확한 타입 : 문자열 배열버전의 함수
//2. 변환 가능한 타입 : 문자열 포인터 버전의 함수
//3. template 사용
//4. 가변인자 사용
//5. error
void foo(char* s1, char* s2)
{

}
int main(){
	foo("orange", "apple");
}