/*

	�迭������ ������ ��� ���� �ڵ�

*/

#include <iostream>

int main(void)
{
	// �迭 ����
	int arr[] = { 1, 2, 3, 4, 5 };

	// �迭�� ù ��° ��Ҹ� ����Ű�� ������ ����
	int* ptr = arr;
	
	// �����͸� ����Ͽ� �迭 ��� ���
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "Element " << i << ": " << *(ptr + i) << std::endl;
	}

	std::cout << std::endl;

	// �迭���� ���� �����ͷ� ����Ͽ� �迭 ��� ���
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "Element " << i << ": " << *(arr + i) << std::endl;
	}

	return 0;
}