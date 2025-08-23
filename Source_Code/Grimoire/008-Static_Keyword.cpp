/*

	Static Keyword 사용 예시

*/

#include <iostream>

int main(void)
{

	auto func = []() -> void
		{
			int var = 0; // 일반 변수 선언
			static int static_var = 0; // static 변수 선언

			var++;
			static_var++;

			std::cout << "Normal variable value: " << var << std::endl;
			std::cout << "Static variable value: " << static_var << std::endl;
			std::cout << std::endl;
		};

	// 첫 번째 호출에서 일반 변수와 static 변수 모두 1으로 출력된다.
	// 첫 번째 호출이 종료되면 일반 변수는 소멸되지만, static 변수는 프로그램 종료 시까지 유지된다.
	func();

	// 두 번째 호출에서 일반 변수는 새로 생성되어 1로 출력되지만, static 변수는 2로 출력된다.
	func();

	// 세 번째 호출에서 일반 변수는 또다시 새로 생성되어 1로 출력되지만, static 변수는 3으로 출력된다.
	func();

	return 0;
}