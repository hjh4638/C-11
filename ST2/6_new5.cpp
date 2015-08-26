#include <iostream>
#include <vector>
using namespace std;

//�������� ����� ȣ���� ����ϴ� ���2. vector�� �޸� �������

int main(){
	vector<int> v(10, 3); // 10���� 3�� �ʱ�ȭ

	v.resize(7); // �� �ڵ��� �˰����� ������ ���ô�

	cout << v.size() << endl; // 7
	cout << v.capacity() << endl; //���� �޸� ũ�� 10

	v.push_back(5);// ���� �ϳ��� �߰��ϰ� 5�� �ʱ�ȭ
	cout << v.size() << endl; // 7
	cout << v.capacity() << endl; //���� �޸� ũ�� 10

	v.shrink_to_fit();// �ʿ���� ������ �����ش޶�
	cout << v.size() << endl; // 8
	cout << v.capacity() << endl; // 8

	// Ŀ���� ���
	vector<int> v2(10, 0);
	v2.push_back(1); // ���� �ϳ� �߰�
					 // �̰�� ���� ũ�� * 1.5�� �ַ� ���
					 // �����Ϸ��� ���� �ٸ� �� �ִ�.
	cout << v2.capacity() << endl;

	//vector�� ����� Ÿ���� �����ϴ� ��츦 ���� �� ���ô�.
	class DBConnect{};
	vector<DBConnect> v3(10); // DBConnect�� �����ڿ���
							  // DB�� �����մϴ�.
	v3.resize(7); // �پ�� 3���� ��ü�� �޸𸮿� �и� �����ֽ��ϴ�.
				  // ������ �Ҹ��ڸ� ȣ���ؼ� DB�� �ݾƾ� �մϴ�.
				  // �Ҹ����� ����� ȣ���� �ʿ� �մϴ�.

	v3.resize(8); // �þ �Ѱ��� ��ü�� �޸𸮿� �̹� �ֽ��ϴ�.
				  // ������ �����ڸ� ȣ���ؼ� DB�� �����ؾ� �մϴ�.
				  // �������� ����� ȣ���� �ʿ��մϴ�.
}