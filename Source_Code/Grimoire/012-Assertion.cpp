/*

	Assertion�� �̿��� ����ó�� ���� �ڵ�

*/

#include <iostream>
#include <cassert>	// Assertion ����� ���� ��� ����

int main(void)
{
	int x = 10;
	int y = 2;

	// y = 0; // y�� 0���� �����Ͽ� ������ ���ܸ� �߻��ô� �ڵ� - �ּ�ó����

	// Assertion�� ����Ͽ� y�� 0�� �ƴ��� Ȯ��
	assert(y != 0); // y�� 0�̸� ���α׷��� �ߴܵǰ� �޽����� ��µ�

	std::cout << "x / y = " << (x / y) << std::endl;

	return 0;
}