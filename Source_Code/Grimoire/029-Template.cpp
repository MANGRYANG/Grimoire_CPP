/*

	Template ��� ���� �ڵ�

*/

#include <iostream>

// ���ø� �Լ� ����
template <typename T>
// ���� Ÿ���� �� �Ű������� �޾� + ������ �����ϴ� �Լ�
// �Ű������� ������ ���� �޾� ���� ����
// �Ű������� const�� �޾� �Լ� ������ ���� ������� �ʵ��� ����
T add(const T& a, const T& b)
{
	return a + b;
}

class Sentence
{
public:
	std::string content;

public:
	Sentence(const std::string& content) : content(content) {}
	~Sentence() = default;

	// + ������ �����ε�
	Sentence operator+(const Sentence& other) const
	{
		return Sentence(this->content + " " + other.content);
	}
};

int main(void)
{
	// add �Լ��� ������ �Ű������� �����Ͽ� ���� ���� ����
	int onePlusOne = add<int>(1, 1);
	std::cout << "1 + 1 = " << onePlusOne << std::endl;

	// Sentence ��ü ����
	Sentence hello("Hello");
	Sentence world("World!");

	// add �Լ��� Sentence ��ü�� �����Ͽ� ���� ��ġ�� ����
	Sentence helloWorld = add<Sentence>(hello, world);
	std::cout << "Combined Sentence: " << helloWorld.content << std::endl;

	return 0;
}