/*

	SOLID 원칙 중 ISP(Interface Segregation Principle) 원칙 예시 코드

	ISP 원칙 : 특정 클라이언트를 위한 인터페이스 여러 개가 범용 인터페이스 하나보다 낫다.

*/

#include <iostream>

class IFlight
{
public:
	virtual void fly() = 0; // 순수 가상 함수

	IFlight() = default;
	virtual ~IFlight() = default;
};

class IDrive
{
public:
	virtual void drive() = 0; // 순수 가상 함수

	IDrive() = default;
	virtual ~IDrive() = default;
};

// 비행기는 날 수도 있고, 운전도 가능하다
// Airplane 클래스는 IFlight, IDrive 인터페이스를 모두 상속받아 구현
class Airplane : public IFlight, public IDrive
{
public:
	void fly() override
	{
		std::cout << "Flying an airplane." << std::endl;
	}
	void drive() override
	{
		std::cout << "Driving an airplane on the runway." << std::endl;
	}

	Airplane() = default;
	~Airplane() override = default;
};

// 자동차는 운전은 가능하지만 날 수 없다
// Car 클래스는 IDrive 인터페이스만 상속받아 구현
class Car : public IDrive
{
public:
	void drive() override
	{
		std::cout << "Driving a car on the road." << std::endl;
	}

	Car() = default;
	~Car() override = default;
};

int main(void)
{
	Airplane* airplane = new Airplane();
	Car* car = new Car();
	
	airplane->fly();
	airplane->drive();
	
	// 만약 IFlight 인터페이스와 IDrive 인터페이스를 하나로 합쳤다면, Car 클래스는 불필요한 fly 메서드를 구현해야 했을 것이다.
	// car->fly(); // 컴파일 에러 발생 (Car 클래스는 추상 클래스 IFlight를 상속받지 않음) 
	car->drive();

	delete airplane;
	delete car;

	return 0;
}