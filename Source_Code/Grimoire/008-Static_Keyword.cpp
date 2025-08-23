/*

	Static Keyword ��� ����

*/

#include <iostream>

int main(void)
{

	auto func = []() -> void
		{
			int var = 0; // �Ϲ� ���� ����
			static int static_var = 0; // static ���� ����

			var++;
			static_var++;

			std::cout << "Normal variable value: " << var << std::endl;
			std::cout << "Static variable value: " << static_var << std::endl;
			std::cout << std::endl;
		};

	// ù ��° ȣ�⿡�� �Ϲ� ������ static ���� ��� 1���� ��µȴ�.
	// ù ��° ȣ���� ����Ǹ� �Ϲ� ������ �Ҹ������, static ������ ���α׷� ���� �ñ��� �����ȴ�.
	func();

	// �� ��° ȣ�⿡�� �Ϲ� ������ ���� �����Ǿ� 1�� ��µ�����, static ������ 2�� ��µȴ�.
	func();

	// �� ��° ȣ�⿡�� �Ϲ� ������ �Ǵٽ� ���� �����Ǿ� 1�� ��µ�����, static ������ 3���� ��µȴ�.
	func();

	return 0;
}