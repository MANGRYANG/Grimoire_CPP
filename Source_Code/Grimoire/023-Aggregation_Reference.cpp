/*

	Aggregation 예시 코드

	Aggregation은 Composition처럼 has-a 관계를 나타낼 때 사용한다.
	Aggregation은 클래스 내에 다른 클래스의 객체를 멤버 변수로 포함하는 것 대신, 포인터나 참조를 통해 연결하는 방식으로 구현한다.
	Aggregation을 사용하면 객체 간의 관계를 유연하게 관리할 수 있으며, 메모리 관리에 대한 책임을 명확하게 분리할 수 있다.
	Aggregation의 가장 큰 특징은 포함된 객체의 생명 주기가 포함하는 객체와 독립적이라는 점이다. (자동으로 소멸되지 않는다)
	
	본 예시 코드에서는 Reference를 사용한 Aggregation을 다룬다.

	Reference를 사용한 Aggregation은 어떤 객체가 다른 객체를 항상 포함해야 하지만 소유권은 외부에 있는 경우에 사용하기 적합하다. (약한 has-a 관계)
	Reference를 사용한 Aggregation은 Pointer를 사용한 Aggregation에 비해 더 강한 연결을 제공한다.
*/

#include <iostream>

class Engine
{
public:
	std::string model;
public:
	// Engine 클래스 생성자
	Engine(const std::string& model) : model(model)
	{
		std::cout << "Engine created: " << model << std::endl;
	}
	// Engine 클래스 소멸자
	~Engine()
	{
		std::cout << "Engine destroyed: " << model << std::endl;
	}
};

class Car
{
public:
	std::string carName;

	// Car은 Engine을 항상 포함해야 하지만, 소유권은 외부에 있다.
	// Aggregation을 사용하여 Engine 객체를 참조로 연결
	// 참조를 통해 연결하는 경우 생성자를 통해 초기화해야 한다. (생성자가 여러 개인 경우에도 모든 생성자에서 초기화 필요)
	Engine& engine;

public:
	// Car 클래스 생성자
	Car(const std::string& carName, Engine& engine) : carName(carName), engine(engine)
	{
		std::cout << "Car created: " << carName << " with engine " << engine.model << std::endl;
	}
	// Car 클래스 소멸자
	~Car()
	{
		std::cout << "Car destroyed: " << carName << std::endl;
	}
};

int main(void)
{
	// Engine 객체는 Car 객체와 독립적으로 생성 및 소멸된다.
	Engine* engine = new Engine("V8 Turbo");

	// Car 객체는 Engine 객체를 포함하지 않고, 단지 참조만 한다.
	Car* car = new Car("Mustang", *engine);

	// Car 객체가 소멸되어도 Engine 객체는 소멸되지 않는다.
	delete car;

	delete engine; // 필요에 따라 Engine 객체를 수동으로 소멸

	return 0;
}