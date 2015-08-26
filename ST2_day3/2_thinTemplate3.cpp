class VectorImpl
{
	void* buffer[100]; // C���� ���� void* ��� �����̳�
	int sz;
public:
	int size(){ return sz; }
	bool empth(){ return sz == 0; }

	void push_front(void* a){}
	void* front(){ return buffer[0]; }
};
// �� Ŭ������ �ٷ� ����ϸ� �׻� ĳ�����ϴ� �������� �ֽ��ϴ�.
// �ڽ� ���ø��� ���� ĳ���ø� å������ �մϴ�.
// core/include/utils/Vector.h �������

// "Thin Template" �̶�� �Ҹ��� ������ ���

// ���ۿ��� "C++ IDioms" ã�ƺ�����
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
	Vector<double> v3; // Vector�� ����Լ��� � �ϱ�� ?
}