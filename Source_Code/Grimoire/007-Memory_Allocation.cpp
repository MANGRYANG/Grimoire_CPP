/*

	���� �޸� �Ҵ� ���� �ڵ�

*/

#include <iostream>

int main(void)
{
	// ���� �޸� �Ҵ�
	int* ptr_i = new int;

	// ���� �޸𸮿� �� �Ҵ�
	*ptr_i = 42;

	// ���� �޸𸮿��� �� ���
	std::cout << *ptr_i << std::endl;

	// ���� �޸� ����
	delete ptr_i;

	std::cout << std::endl;

	// �迭 ���� �޸� �Ҵ�
	int* ptr_arr = new int[5];

	// �迭 ���� �޸𸮿� �� �Ҵ�
	for (int i = 0; i < 5; ++i)
	{
		ptr_arr[i] = i + 1; // 1���� 5������ �� �Ҵ�
	}

	// �迭 ���� �޸𸮿��� �� ���
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Element " << i << ": " << ptr_arr[i] << std::endl;
	}

	// �迭 ���� �޸� ����
	delete[] ptr_arr;

	return 0;
}