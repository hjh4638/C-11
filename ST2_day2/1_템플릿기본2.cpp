template<typename T> T square(T a){
	return a*a;
}
int main(){
	short s = 3;

	square(3); //int 버전
	//square(s); //short 버전
	square<int>(s);
}
//VC++ 명령 프롬프트 실행 