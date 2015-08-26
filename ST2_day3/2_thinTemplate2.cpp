// T를 사용하지 않은 모든 멤버 함수는 부모 클래스로 만든다.
// 부모 함수 2개 + 자식 함수 2개 * 3개 타입 => 8개 함수
class VectorImpl
{
	int sz;
public:
	int size(){ return sz; }
	bool empth(){ return sz == 0; }

};
template<typename T> class Vector : public VectorImpl
{
	T buffer[100];
public:
	void push_front(T a){}
	T front(){ return buffer[0];}
};

int main()
{
	Vector<int> v1;
	Vector<char> v2;
	Vector<double> v3; // Vector의 멤버함수는 몇개 일까요 ?
}