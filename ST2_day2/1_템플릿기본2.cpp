template<typename T> T square(T a){
	return a*a;
}
int main(){
	short s = 3;

	square(3); //int ����
	//square(s); //short ����
	square<int>(s);
}
//VC++ ��� ������Ʈ ���� 