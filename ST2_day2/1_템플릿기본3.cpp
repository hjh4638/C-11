//square : �Լ��� ����� ��(template)
//square<int> : �Լ�!
#include <stdio.h>

template<typename T> T square(T a){
	return a*a;
}
int main(){
	printf("%p\n", &square);//�ɱ��? �߻����ϼ���.!
	printf("%d\n", &square<int>);//ok
}