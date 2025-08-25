/*

	Composition ���� �ڵ�

	is-a ���踦 ��Ÿ���� ���(Inheritance)�� �ٸ��� Composition�� has-a ���踦 ��Ÿ�� �� ����Ѵ�.
	Composition�� Ŭ���� ���� �ٸ� Ŭ������ ��� ������ �����ϴ� ������� �����ȴ�.
	Composition�� ����ϸ� ��ü ���� ���踦 ��Ȯ�ϰ� ǥ���� �� ������, �ڵ��� ���뼺�� ������������ ���� �� �ִ�.

*/

#include <iostream>

class Paper
{
public:
	std::string content;

public:
	Paper() : content("Empty")
	{
		std::cout << "Paper created with content: " << content << std::endl;
	}

	~Paper()
	{
		std::cout << "Paper destroyed with content: " << content << std::endl;
	}
};

// Book Ŭ������ Paper Ŭ������ �����Ͽ� Composition ���踦 �����Ѵ�.
// �̿� ���� �����ϰ� �Ǹ� Book ��ü�� ������ �� Paper ��ü�� �Բ� �����Ǹ�, Book ��ü�� �Ҹ�� �� Paper ��ü�� �Բ� �Ҹ�ȴ�.
class Book
{
public:
	// Composition�� ����Ͽ� Paper ��ü�� ��� ������ ����
	Paper paper; // Book�� Paper�� ����(has-a ����)

	std::string title;
	std::string author;

public:
	Book() : title("Untitled"), author("Unknown")
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
	// C++������ ��� ������ ���� ������ �� ��ü�� �����ڰ� ȣ��ȴ�.
	// ��, Book ��ü�� �����ڰ� ȣ��Ǳ� �� Paper ��ü�� �����ȴ�.
	Book comicBook;

	// C++������ ��ü�� �Ҹ��ڰ� ���� ȣ��� �� ��� ������ �Ҹ�ȴ�.
	// ��, Book ��ü�� �Ҹ��ڰ� ȣ��� �� Paper ��ü�� �Ҹ�ȴ�.

	return 0;
}