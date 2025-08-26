/*

	Template Specialization ��� ���� �ڵ�

*/

#include <iostream>

// ���ø� �Լ� ����
// ���� Ÿ���� �� �Ű������� �޾� + ������ �����ϴ� �Լ�
template <typename T>
T add(const T& a, const T& b)
{
	return a + b;
}

// double Ÿ�Կ� ���ؼ��� ���� ���� �� �ݿø��ϵ��� Ư��ȭ
template <>
double add<double>(const double& a, const double& b)
{
	return static_cast<int>(a + b + 0.5); // �ݿø��Ͽ� ���� �κи� ��ȯ
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

	// add �Լ��� double�� �Ű������� �����Ͽ� ���� ���� (Ư��ȭ�� �Լ� ȣ��)
	double twoPointFivePlusThreePointFive = add<double>(2.5, 3.5);
	std::cout << "2.7 + 3.6 (rounded) = " << twoPointFivePlusThreePointFive << std::endl;

	// Sentence ��ü ����
	Sentence hello("Hello");
	Sentence world("World!");

	// add �Լ��� Sentence ��ü�� �����Ͽ� ���� ��ġ�� ����
	Sentence helloWorld = add<Sentence>(hello, world);
	std::cout << "Combined Sentence: " << helloWorld.content << std::endl;

	return 0;
}