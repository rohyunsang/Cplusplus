#include <iostream>
#include <cstdlib>

using namespace std;

int comp (const void* a, const void* b) {

	return *(int*)b - *(int*)a;
}

int main() {

	int arr[] = { 30,302,2132,123202,3232032,3223 };

	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), comp);


	for (auto& a : arr)
		cout << a << " ";
	return 0;
}

//const void *�� void�� ����� ����Ű�� �����Ͷ�� ���Դϴ�. 
//��, qsort �Լ��� ���� compare �Լ��� �����͸� ���� �޾��� �� �����Ͱ� ����Ű�� ���� ����Դϴ�. 
//����  compare �Լ� �ȿ����� ���� ���Ƿ� �����ؼ��� �� �˴ϴ�.

// void *ptr;  :  void ������ ����

//�⺻������ C ���� �ڷ����� �ٸ� �����ͳ��� �޸� �ּҸ� �����ϸ� ������ ���(warning)�� �߻��մϴ�. 
//������ void �����ʹ� �ڷ����� �������� ���� Ư�� ������ � �ڷ������� �� �����͵� ��� ������ �� �ֽ��ϴ�.
//�ݴ�� �پ��� �ڷ������� �� �����Ϳ��� void �����͸� ������ ���� �ֽ��ϴ�. 
//�̷� Ư�� ������ void �����ʹ� ���� �����Ͷ�� �մϴ�.
