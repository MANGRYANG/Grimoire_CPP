/*

	SOLID ��Ģ �� OCP(Open-Closed Principle) ��Ģ ���� �ڵ�

	OCP ��Ģ :Ȯ�忡�� ���� �־�� �ϰ�, ���� �־�� �Ѵ�.
	OCP ��Ģ�� �ַ� �߻� Ŭ������ Ȱ���Ͽ� ���� �����ϴ�.

*/

#include <iostream>

// Mouse Ŭ������ �߻� Ŭ������ �����Ͽ� �������̽� ������ �ϵ��� ��
// ���ο� ������ Mouse�� �߰��Ǵ� ���, ���� Ŭ������ �������� �ʰ� ���ο� Ŭ������ �߰��Ͽ� ����� Ȯ���� �� ����
class Mouse
{
public:
	virtual void connect() = 0; // ���� ���� �Լ��� ����
	Mouse() = default;
	virtual ~Mouse() = default; // ���� �Ҹ���
};

class USBMouse : public Mouse
{
public:
	void connect() override
	{
		std::cout << "USB Mouse connected." << std::endl;
	}
	USBMouse() = default;
	~USBMouse() override = default;
};

class WirelessMouse : public Mouse
{
public:
	void connect() override
	{
		std::cout << "Wireless Mouse connected." << std::endl;
	}
	WirelessMouse() = default;
	~WirelessMouse() override = default;
};

// ���ο� ������ Mouse �߰� -> TrackballMouse
/*
class TrackballMouse : public Mouse
{
public:
	void connect() override
	{
		std::cout << "Trackball Mouse connected." << std::endl;
	}
	TrackballMouse() = default;
	~TrackballMouse() override = default;
};
*/

int main(void)
{
	Mouse* usbMouse = new USBMouse();
	usbMouse->connect();
	
	Mouse* wirelessMouse = new WirelessMouse();
	wirelessMouse->connect();

	delete usbMouse;
	delete wirelessMouse;
	
	return 0;
}