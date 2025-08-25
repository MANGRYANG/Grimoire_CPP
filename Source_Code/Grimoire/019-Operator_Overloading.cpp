/*

	������ �����ε� ���� �ڵ�

	return_type operator-symbol(parameter) (operator Ű����� symbol�� �ٿ��� �ڵ� �ۼ�)
	�� ������ ���� ������ �����ε��� ������ �� �ִ�.
	
*/

#include <iostream>

class Sentence
{
public:
	std::string str;	// ������ ������ ��� ����
	
	Sentence(std::string s) : str(s) {}  // ������
	~Sentence() {}  // �Ҹ���

	void print_str() const
	{
		std::cout << str << std::endl;  // ���� ��� �Լ�
	}

	// ������ �����ε�: + �����ڸ� ����Ͽ� �� ������ ��ġ�� ��� ����
	// Sentence ��ü�� �Ű������� �޾� ���ο� Sentence ��ü�� ��ȯ
	Sentence operator+(const Sentence &sentence)
	{
		return Sentence(str + " " + sentence.str);  // �� ������ ���ļ� ���ο� Sentence ��ü ��ȯ
	}
};

int main(void)
{
	Sentence hello("Hello");
	Sentence world("World");
	// + ������ �����ε��� ���� �� ��ü�� ������ + �����ڷ� ������ �� ����
	Sentence hello_world = hello + world;

	hello_world.print_str();  // "Hello World" ���

	return 0;
}