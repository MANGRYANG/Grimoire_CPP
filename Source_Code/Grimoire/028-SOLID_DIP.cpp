/*

	SOLID ��Ģ �� DIP(Dependency Inversion Principle) ��Ģ ���� �ڵ�

	DIP ��Ģ : ����� ����� ������ ��⿡ �����ؼ��� �� �Ǹ�, �� �� �߻� ���̾ �����ؾ� �Ѵ�.

	�� 021-Composition.cpp ������ DIP ��Ģ�� �������� �����Ͽ� �ۼ��� �ڵ�

*/

#include <iostream>

// �߻� Ŭ���� IPaper ����
class IPaper
{
public:
	std::string content;

	virtual void printContent() = 0; // ���� ���� �Լ��� ����

public:
	IPaper() : content("Empty") {}

	virtual ~IPaper() {};	// ���� �Ҹ���

};

// IPaper �߻� Ŭ������ ��ӹ޴� A4Paper Ŭ���� ����
class A4Paper : public IPaper
{
public:

	void printContent() override
	{
		std::cout << "A4 Paper Content: " << content << std::endl;
	}

	A4Paper()
	{
		content = "A4 Paper Content";
		std::cout << "A4 Paper created with content: " << content << std::endl;
	}
	~A4Paper() override
	{
		std::cout << "A4 Paper destroyed with content: " << content << std::endl;
	}
};

// IPaper �߻� Ŭ������ ��ӹ޴� B4Paper Ŭ���� ����
class B4Paper : public IPaper
{
public:
	B4Paper()
	{
		content = "B4 Paper Content";
		std::cout << "B4 Paper created with content: " << content << std::endl;
	}
	~B4Paper() override
	{
		std::cout << "B4 Paper destroyed with content: " << content << std::endl;
	}
};

// Book�� IPaper�� �����Ѵ�
class Book
{
public:
	// composition�� ����ϰ� �Ǹ� Book Ŭ������ �����ؾ� �ϴ� IPaper Ŭ������ ��ü�� �ʿ��ϴ�.
	// �׷��� C++������ �߻� Ŭ������ ��ü�� ������ �� �����Ƿ�, composition�� ����� �� ����.
	// �̿� ����, Aggregation�� ����Ͽ� IPaper Ŭ������ ������ ��� ������ �����ϵ��� �����Ͽ���.
	// �Ʒ��� ���� ��� ������ �����ϸ� IPaper Ŭ������ �����ϸ�, ��ü���� Ŭ����(A4Paper ��)���� �������� �ʴ´�. (DIP ��Ģ �ؼ�)
	IPaper& paper;

	std::string title;
	std::string author;

public:
	Book(IPaper& param_paper) : title("Untitled"), author("Unknown"), paper(param_paper)
	{
		std::cout << "Book created: " << title << " by " << author << std::endl;
	}
	~Book()
	{
		std::cout << "Book destroyed: " << title << " by " << author << std::endl;
	}
};

int main(void)
{
	A4Paper a4Paper;
	Book comicBook(a4Paper); // Book�� A4Paper�� �������� �ʰ� IPaper�� ����

	comicBook.paper.printContent();

	return 0;
}