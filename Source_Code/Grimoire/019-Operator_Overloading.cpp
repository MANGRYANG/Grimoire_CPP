/*

	연산자 오버로딩 예시 코드

	return_type operator-symbol(parameter) (operator 키워드와 symbol은 붙여서 코드 작성)
	위 형식을 통해 연산자 오버로딩을 구현할 수 있다.
	
*/

#include <iostream>

class Sentence
{
public:
	std::string str;	// 문장을 저장할 멤버 변수
	
	Sentence(std::string s) : str(s) {}  // 생성자
	~Sentence() {}  // 소멸자

	void print_str() const
	{
		std::cout << str << std::endl;  // 문장 출력 함수
	}

	// 연산자 오버로딩: + 연산자를 사용하여 두 문장을 합치는 기능 구현
	// Sentence 객체를 매개변수로 받아 새로운 Sentence 객체를 반환
	Sentence operator+(const Sentence &sentence)
	{
		return Sentence(str + " " + sentence.str);  // 두 문장을 합쳐서 새로운 Sentence 객체 반환
	}
};

int main(void)
{
	Sentence hello("Hello");
	Sentence world("World");
	// + 연산자 오버로딩을 통해 두 객체의 문장을 + 연잔자로 결합할 수 있음
	Sentence hello_world = hello + world;

	hello_world.print_str();  // "Hello World" 출력

	return 0;
}