/*

	SOLID 원칙 중 SRP(Single Responsibility Principle) 원칙 예시 코드

	SRP 원칙 : 하나의 클래스는 하나의 책임만 가져야 한다. 즉, 클래스는 하나의 기능만 수행해야 한다.

*/

#include <iostream>

// InputHandler는 입력 처리에 대한 책임만 가진다.
// 입력 처리에 대한 기능이 변경될 필요가 있다면 InputHandler 클래스만 수정하면 된다.
class InputHandler {
public:
	void handleInput()
	{
		std::cout << "Handling input..." << std::endl;
	}
};

// DataProcessor는 데이터 처리에 대한 책임만 가진다.
// 데이터 처리에 대한 기능이 변경될 필요가 있다면 DataProcessor 클래스만 수정하면 된다.
class DataProcessor {
public:
	void processData()
	{
		std::cout << "Processing data..." << std::endl;
	}
};

// OutputHandler는 출력 처리에 대한 책임만 가진다.
// 출력 처리에 대한 기능이 변경될 필요가 있다면 OutputHandler 클래스만 수정하면 된다.
class OutputHandler {
public:
	void handleOutput()
	{
		std::cout << "Handling output..." << std::endl;
	}
};

int main(void)
{
	InputHandler inputHandler;
	DataProcessor dataProcessor;
	OutputHandler outputHandler;

	inputHandler.handleInput();
	dataProcessor.processData();
	outputHandler.handleOutput();
	
	return 0;
}