class VectorImpl
{
	void* buffer[100]; // C에서 배우는 void* 기반 컨테이너
	int sz;
public:
	int size(){ return sz; }
	bool empth(){ return sz == 0; }

	void push_front(void* a){}
	void* front(){ return buffer[0]; }
};
// 위 클래스를 바로 사용하면 항상 캐스팅하는 불편함이 있습니다.
// 자식 템플릿을 만들어서 캐스팅만 책임지게 합니다.
// core/include/utils/Vector.h 열어보세요

// "Thin Template" 이라고 불리는 디자인 기술

// 구글에서 "C++ IDioms" 찾아보세요
template<typename T> class Vector : private VectorImpl
{
public:
	inline void push_front(T a){ VectorImpl::push_front((void*)a)}
	inline T front(){ return static_cast<T>(VectorImpl::front()); }

	int size(){ return VectorImpl::size(); }
	bool empth(){ return VectorImpl::empth(); }
};

int main()
{
	Vector<int> v1;
	Vector<char> v2;
	Vector<double> v3; // Vector의 멤버함수는 몇개 일까요 ?
}