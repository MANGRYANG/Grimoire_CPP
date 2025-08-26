/*

	SOLID ��Ģ �� SRP(Single Responsibility Principle) ��Ģ ���� �ڵ�

	SRP ��Ģ : �ϳ��� Ŭ������ �ϳ��� å�Ӹ� ������ �Ѵ�. ��, Ŭ������ �ϳ��� ��ɸ� �����ؾ� �Ѵ�.

*/

#include <iostream>

// InputHandler�� �Է� ó���� ���� å�Ӹ� ������.
// �Է� ó���� ���� ����� ����� �ʿ䰡 �ִٸ� InputHandler Ŭ������ �����ϸ� �ȴ�.
class InputHandler {
public:
	void handleInput()
	{
		std::cout << "Handling input..." << std::endl;
	}
};

// DataProcessor�� ������ ó���� ���� å�Ӹ� ������.
// ������ ó���� ���� ����� ����� �ʿ䰡 �ִٸ� DataProcessor Ŭ������ �����ϸ� �ȴ�.
class DataProcessor {
public:
	void processData()
	{
		std::cout << "Processing data..." << std::endl;
	}
};

// OutputHandler�� ��� ó���� ���� å�Ӹ� ������.
// ��� ó���� ���� ����� ����� �ʿ䰡 �ִٸ� OutputHandler Ŭ������ �����ϸ� �ȴ�.
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