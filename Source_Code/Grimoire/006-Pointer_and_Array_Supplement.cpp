/*

	�迭������ ������ ��� ���� �ڵ� - ����

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

	std::cout << sizeof(ptr) << " bytes" << std::endl;	// int* �������� ũ���� 8 bytes�� ��µȴ�.

	std::cout << std::endl;

	// �迭���� ���� �����ͷ� ����Ͽ� �迭 ��� ���
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "Element " << i << ": " << *(arr + i) << std::endl;
	}

	std::cout << sizeof(arr) << " bytes" << std::endl;	// int �迭�� ũ���� 20 bytes�� ��µȴ�. (5 * sizeof(int) = 5 * 4 = 20)

	return 0;
}