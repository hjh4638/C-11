#include <algorithm>
using namespace std;

int main(){
	int x[10];

	sort(x, x + 10, [](int a, int b){return a < b; });
	
	//�� ������ ���� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.

	class closure_object{
	public:
		// �Լ� ��ü�� �ٽ� () ������
		inline bool operator()(int a, int b) const{
			return a < b;
		}
	};
	closure_object f;
	sort(x, x + 10, f);

	//��Ȯ���� �ӽ� ��ü�� �����մϴ�.
	sort(x, x + 10, closure_object());
}