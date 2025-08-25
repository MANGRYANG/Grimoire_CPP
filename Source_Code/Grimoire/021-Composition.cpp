/*

	Composition 예시 코드

	is-a 관계를 나타내는 상속(Inheritance)와 다르게 Composition은 has-a 관계를 나타낼 때 사용한다.
	Composition은 클래스 내에 다른 클래스를 멤버 변수로 포함하는 방식으로 구현된다.
	Composition을 사용하면 객체 간의 관계를 명확하게 표현할 수 있으며, 코드의 재사용성과 유지보수성을 높일 수 있다.

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

// Book 클래스는 Paper 클래스를 포함하여 Composition 관계를 형성한다.
// 이와 같이 설정하게 되면 Book 객체가 생성될 때 Paper 객체도 함께 생성되며, Book 객체가 소멸될 때 Paper 객체도 함께 소멸된다.
class Book
{
public:
	// Composition을 사용하여 Paper 객체를 멤버 변수로 포함
	Paper paper; // Book은 Paper를 가짐(has-a 관계)

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
	// C++에서는 멤버 변수가 먼저 생성된 후 객체의 생성자가 호출된다.
	// 즉, Book 객체의 생성자가 호출되기 전 Paper 객체가 생성된다.
	Book comicBook;

	// C++에서는 객체의 소멸자가 먼저 호출된 후 멤버 변수가 소멸된다.
	// 즉, Book 객체의 소멸자가 호출된 후 Paper 객체가 소멸된다.

	return 0;
}