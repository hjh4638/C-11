//square : 함수를 만드는 툴(template)
//square<int> : 함수!
#include <stdio.h>

template<typename T> T square(T a){
	return a*a;
}
int main(){
	printf("%p\n", &square);//될까요? 잘생각하세요.!
	printf("%d\n", &square<int>);//ok
}