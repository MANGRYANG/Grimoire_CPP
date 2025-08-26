/*

	SOLID ��Ģ �� ISP(Interface Segregation Principle) ��Ģ ���� �ڵ�

	ISP ��Ģ : Ư�� Ŭ���̾�Ʈ�� ���� �������̽� ���� ���� ���� �������̽� �ϳ����� ����.

*/

#include <iostream>

class IFlight
{
public:
	virtual void fly() = 0; // ���� ���� �Լ�

	IFlight() = default;
	virtual ~IFlight() = default;
};

class IDrive
{
public:
	virtual void drive() = 0; // ���� ���� �Լ�

	IDrive() = default;
	virtual ~IDrive() = default;
};

// ������ �� ���� �ְ�, ������ �����ϴ�
// Airplane Ŭ������ IFlight, IDrive �������̽��� ��� ��ӹ޾� ����
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

// �ڵ����� ������ ���������� �� �� ����
// Car Ŭ������ IDrive �������̽��� ��ӹ޾� ����
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
	
	// ���� IFlight �������̽��� IDrive �������̽��� �ϳ��� ���ƴٸ�, Car Ŭ������ ���ʿ��� fly �޼��带 �����ؾ� ���� ���̴�.
	// car->fly(); // ������ ���� �߻� (Car Ŭ������ �߻� Ŭ���� IFlight�� ��ӹ��� ����) 
	car->drive();

	delete airplane;
	delete car;

	return 0;
}