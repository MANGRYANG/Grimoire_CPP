/*

	SOLID ��Ģ �� LSP(Liskov Substitution Principle) ��Ģ ���� �ڵ�

	LSP ��Ģ : ���� Ŭ������ ������ ���� Ŭ������ ��ü�� �� �־�� �Ѵ�.

*/

#include <iostream>

class Car
{
public:
	virtual void drive() = 0; // ���� ���� �Լ��� ����

	Car() = default;
	virtual ~Car() = default; // ���� �Ҹ���
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

// Car Ŭ���� �����͸� �Ű������� �޾� drive �޼��带 ȣ���ϴ� �Լ�
static void testDrive(Car* car)
{
	car->drive();
}

int main(void)
{
	Car* gasolineCar = new GasolineCar();
	Car* electricCar = new ElectricCar();

	// ���� Ŭ������ Car�� ���ڷ� �޴� testDrive �Լ��� ���� Ŭ������ ��ü�� �����Ͽ��� ���� ������
	testDrive(gasolineCar);
	testDrive(electricCar);
	
	delete gasolineCar;
	delete electricCar;
	
	return 0;

}