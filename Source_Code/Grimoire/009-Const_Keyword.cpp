/*

	Const Keyword ��� ����

*/

#include <iostream>

int main(void)
{
	// const Ű���带 ����� ������ ���ȭ

	// �Ϲ� ���� ����
	char a = 'A';
	char b = 'B';
	char c = 'C';

	// const Ű���带 ����Ͽ� ���ȭ�� ���� ����
	const char d = 'D';

	a = 'a'; // �Ϲ� ������ �� ���� ����
	// d = 'd'; // const ������ �� ���� �Ұ����Ͽ� �ּ� ó��


	// const Ű���带 ����� �������� ���ȭ

	char* ptr_a = &a; // �Ϲ� ������ ����
	*ptr_a = 'A'; // �����Ͱ� ����Ű�� �� ���� ����

	std::cout << *ptr_a << std::endl; // a�� ���� 'A'�� ��µ�


	const char* ptr_b = &b; // const ������ ����
	// *ptr_b = 'b'; // ������ ������ ����Ű�� ���� ������ �� �����Ƿ� �ּ� ó��
	ptr_b = &c; // ������ ���� ��ü�� �ٸ� �ּҸ� ����ų �� ����

	std::cout << *ptr_b << std::endl; // c�� ���� 'C'�� ��µ�


	char* const ptr_c = &c; // const ������ ����
	*ptr_c = 'c'; // �����Ͱ� ����Ű�� ���� ���� ����
	// ptr_c = &b; // ���ȭ�� ������ ptr_c�� �ٸ� �ּҸ� ����ų �� �����Ƿ� �ּ� ó��

	std::cout << *ptr_c << std::endl; // c�� ���� 'c'�� ��µ�

	return 0;
}