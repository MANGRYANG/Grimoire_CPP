/*

	Generic Pointer ��� ���� �ڵ�

	Generic Pointer : void* Ÿ���� �����ͷ�, � Ÿ���� ������ ����ų �� �ִ� �����͸� �ǹ��Ѵ�.
	�پ��� Ÿ���� ������ ó���� �� ������ Ÿ�Կ� ���� ������ ĳ������ �����Ͽ� ����Ѵ�.

*/

#include <iostream>

int main(void)
{
	int int_value = 42; // ������ ���� ����
	double double_value = 3.14; // �Ǽ��� ���� ����

	// Generic Pointer ����
	void* generic_pointer;

	// ������ ������ �ּҸ� Generic Pointer�� ����
	generic_pointer = &int_value;
	// Generic Pointer�� int*�� ĳ�����Ͽ� �����Ͱ� ����Ű�� �� ���
	std::cout << *static_cast<int*>(generic_pointer) << std::endl;

	// �Ǽ��� ������ �ּҸ� Generic Pointer�� ����
	generic_pointer = &double_value;
	// Generic Pointer�� double*�� ĳ�����Ͽ� �����Ͱ� ����Ű�� �� ���
	std::cout << *static_cast<double*>(generic_pointer) << std::endl;

	return 0;
}