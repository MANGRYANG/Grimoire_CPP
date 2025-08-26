/*

	SOLID 원칙 중 DIP(Dependency Inversion Principle) 원칙 예시 코드

	DIP 원칙 : 고수준 모듈은 저수준 모듈에 의존해서는 안 되며, 둘 다 추상 레이어에 의존해야 한다.

	※ 021-Composition.cpp 파일을 DIP 원칙을 따르도록 수정하여 작성한 코드

*/

#include <iostream>

// 추상 클래스 IPaper 정의
class IPaper
{
public:
	std::string content;

	virtual void printContent() = 0; // 순수 가상 함수로 선언

public:
	IPaper() : content("Empty") {}

	virtual ~IPaper() {};	// 가상 소멸자

};

// IPaper 추상 클래스를 상속받는 A4Paper 클래스 정의
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

// IPaper 추상 클래스를 상속받는 B4Paper 클래스 정의
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

// Book은 IPaper를 포함한다
class Book
{
public:
	// composition을 사용하게 되면 Book 클래스가 의존해야 하는 IPaper 클래스의 객체가 필요하다.
	// 그러나 C++에서는 추상 클래스의 객체를 생성할 수 없으므로, composition을 사용할 수 없다.
	// 이에 따라, Aggregation을 사용하여 IPaper 클래스의 참조를 멤버 변수로 포함하도록 구현하였다.
	// 아래와 같이 멤버 변수를 설정하면 IPaper 클래스에 의존하며, 구체적인 클래스(A4Paper 등)에는 의존하지 않는다. (DIP 원칙 준수)
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
	Book comicBook(a4Paper); // Book은 A4Paper에 의존하지 않고 IPaper에 의존

	comicBook.paper.printContent();

	return 0;
}