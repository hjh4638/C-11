template<typename T> class Vector
{
	T buffer[100];
	int sz;
public:
	void push_front(T a){}
	T front(){
		buffer[0];
	}
	int size(){ return sz; }
	bool empth(){ return sz == 0; }
};

int main()
{
	Vector<int> v1;
	Vector<char> v2;
	Vector<double> v3; // Vector의 멤버함수는 몇개 일까요 ?
}