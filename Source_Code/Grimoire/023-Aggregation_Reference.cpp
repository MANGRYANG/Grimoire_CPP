/*

	Aggregation ���� �ڵ�

	Aggregation�� Compositionó�� has-a ���踦 ��Ÿ�� �� ����Ѵ�.
	Aggregation�� Ŭ���� ���� �ٸ� Ŭ������ ��ü�� ��� ������ �����ϴ� �� ���, �����ͳ� ������ ���� �����ϴ� ������� �����Ѵ�.
	Aggregation�� ����ϸ� ��ü ���� ���踦 �����ϰ� ������ �� ������, �޸� ������ ���� å���� ��Ȯ�ϰ� �и��� �� �ִ�.
	Aggregation�� ���� ū Ư¡�� ���Ե� ��ü�� ���� �ֱⰡ �����ϴ� ��ü�� �������̶�� ���̴�. (�ڵ����� �Ҹ���� �ʴ´�)
	
	�� ���� �ڵ忡���� Reference�� ����� Aggregation�� �ٷ��.

	Reference�� ����� Aggregation�� � ��ü�� �ٸ� ��ü�� �׻� �����ؾ� ������ �������� �ܺο� �ִ� ��쿡 ����ϱ� �����ϴ�. (���� has-a ����)
	Reference�� ����� Aggregation�� Pointer�� ����� Aggregation�� ���� �� ���� ������ �����Ѵ�.
*/

#include <iostream>

class Engine
{
public:
	std::string model;
public:
	// Engine Ŭ���� ������
	Engine(const std::string& model) : model(model)
	{
		std::cout << "Engine created: " << model << std::endl;
	}
	// Engine Ŭ���� �Ҹ���
	~Engine()
	{
		std::cout << "Engine destroyed: " << model << std::endl;
	}
};

class Car
{
public:
	std::string carName;

	// Car�� Engine�� �׻� �����ؾ� ������, �������� �ܺο� �ִ�.
	// Aggregation�� ����Ͽ� Engine ��ü�� ������ ����
	// ������ ���� �����ϴ� ��� �����ڸ� ���� �ʱ�ȭ�ؾ� �Ѵ�. (�����ڰ� ���� ���� ��쿡�� ��� �����ڿ��� �ʱ�ȭ �ʿ�)
	Engine& engine;

public:
	// Car Ŭ���� ������
	Car(const std::string& carName, Engine& engine) : carName(carName), engine(engine)
	{
		std::cout << "Car created: " << carName << " with engine " << engine.model << std::endl;
	}
	// Car Ŭ���� �Ҹ���
	~Car()
	{
		std::cout << "Car destroyed: " << carName << std::endl;
	}
};

int main(void)
{
	// Engine ��ü�� Car ��ü�� ���������� ���� �� �Ҹ�ȴ�.
	Engine* engine = new Engine("V8 Turbo");

	// Car ��ü�� Engine ��ü�� �������� �ʰ�, ���� ������ �Ѵ�.
	Car* car = new Car("Mustang", *engine);

	// Car ��ü�� �Ҹ�Ǿ Engine ��ü�� �Ҹ���� �ʴ´�.
	delete car;

	delete engine; // �ʿ信 ���� Engine ��ü�� �������� �Ҹ�

	return 0;
}