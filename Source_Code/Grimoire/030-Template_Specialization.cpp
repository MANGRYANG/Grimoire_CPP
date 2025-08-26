/*

	Template Specialization 사용 예시 코드

*/

#include <iostream>

// 템플릿 함수 정의
// 같은 타입의 두 매개변수를 받아 + 연산을 수행하는 함수
template <typename T>
T add(const T& a, const T& b)
{
	return a + b;
}

// double 타입에 대해서는 덧셈 수행 후 반올림하도록 특수화
template <>
double add<double>(const double& a, const double& b)
{
	return static_cast<int>(a + b + 0.5); // 반올림하여 정수 부분만 반환
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

	// add 함수에 double형 매개변수를 전달하여 덧셈 수행 (특수화된 함수 호출)
	double twoPointFivePlusThreePointFive = add<double>(2.5, 3.5);
	std::cout << "2.7 + 3.6 (rounded) = " << twoPointFivePlusThreePointFive << std::endl;

	// Sentence 객체 생성
	Sentence hello("Hello");
	Sentence world("World!");

	// add 함수에 Sentence 객체를 전달하여 문장 합치기 수행
	Sentence helloWorld = add<Sentence>(hello, world);
	std::cout << "Combined Sentence: " << helloWorld.content << std::endl;

	return 0;
}