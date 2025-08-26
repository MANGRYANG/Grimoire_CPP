/*

	Template 사용 예시 코드

*/

#include <iostream>

// 템플릿 함수 정의
template <typename T>
// 같은 타입의 두 매개변수를 받아 + 연산을 수행하는 함수
// 매개변수를 참조를 통해 받아 복사 방지
// 매개변수를 const로 받아 함수 내에서 값이 변경되지 않도록 설정
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

	// + 연산자 오버로딩
	Sentence operator+(const Sentence& other) const
	{
		return Sentence(this->content + " " + other.content);
	}
};

int main(void)
{
	// add 함수에 정수형 매개변수를 전달하여 정수 덧셈 수행
	int onePlusOne = add<int>(1, 1);
	std::cout << "1 + 1 = " << onePlusOne << std::endl;

	// Sentence 객체 생성
	Sentence hello("Hello");
	Sentence world("World!");

	// add 함수에 Sentence 객체를 전달하여 문장 합치기 수행
	Sentence helloWorld = add<Sentence>(hello, world);
	std::cout << "Combined Sentence: " << helloWorld.content << std::endl;

	return 0;
}