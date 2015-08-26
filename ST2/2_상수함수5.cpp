#include <iostream>
using namespace std;

//���� ����� : �ܺο��� �ٶ󺼶��� ��� �Լ��� �Ǿ������� ���������δ� ��� ������ ���� �����ؾ� �ϴ� ����
// 1. ���ϴ� ����� mutable�� !!

//2. ������ ���� �Ͱ� ���ϴ� ���� �и��Ǿ�� �Ѵ�.
// ��� �Լ����� ���ؾ� �ϴ� ���� �ִٸ� ������ ����ü�� �и��Ѵ�.
struct Cache{
	char data[32];
	bool valid;
};
class Point{
	int x, y;
	Cache* pCache;

public:
	Point(int a = 0, int b = 0) :x(a), y(b){
		pCache = new Cache;
		pCache->valid = false;
	}

	//��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� �Լ� : java, C#�� �ִ� ����
	char* toString() const
	{
		if (pCache->valid == false){
			sprintf_s(pCache->data, "%d, %d", x, y);
			pCache->valid = true;
		}
		return pCache->data;
	}
};
	int main(){
		Point p(1, 2);
		cout << p.toString() << endl;
		cout << p.toString() << endl;
	}