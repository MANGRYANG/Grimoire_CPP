/*

	SOLID 원칙 중 LSP(Liskov Substitution Principle) 원칙 예시 코드

	LSP 원칙 : 하위 클래스는 언제나 상위 클래스를 대체할 수 있어야 한다.

*/

#include <iostream>

class Car
{
public:
	virtual void drive() = 0; // 순수 가상 함수로 선언

	Car() = default;
	virtual ~Car() = default; // 가상 소멸자
};

class GasolineCar : public Car
{
public:
	void drive() override
	{
		std::cout << "Driving a gasoline car." << std::endl;
	}
	GasolineCar() = default;
	~GasolineCar() override = default;
};

class ElectricCar : public Car
{
public:
	void drive() override
	{
		std::cout << "Driving an electric car." << std::endl;
	}
	ElectricCar() = default;
	~ElectricCar() override = default;
};

// Car 클래스 포인터를 매개변수로 받아 drive 메서드를 호출하는 함수
static void testDrive(Car* car)
{
	car->drive();
}

int main(void)
{
	Car* gasolineCar = new GasolineCar();
	Car* electricCar = new ElectricCar();

	// 상위 클래스인 Car를 인자로 받는 testDrive 함수에 하위 클래스의 객체를 전달하여도 정상 동작함
	testDrive(gasolineCar);
	testDrive(electricCar);
	
	delete gasolineCar;
	delete electricCar;
	
	return 0;

}