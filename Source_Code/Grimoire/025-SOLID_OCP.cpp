/*

	SOLID 원칙 중 OCP(Open-Closed Principle) 원칙 예시 코드

	OCP 원칙 :확장에는 열려 있어야 하고, 닫혀 있어야 한다.
	OCP 원칙은 주로 추상 클래스를 활용하여 구현 가능하다.

*/

#include <iostream>

// Mouse 클래스를 추상 클래스로 선언하여 인터페이스 역할을 하도록 함
// 새로운 형태의 Mouse가 추가되는 경우, 기존 클래스를 수정하지 않고 새로운 클래스를 추가하여 기능을 확장할 수 있음
class Mouse
{
public:
	virtual void connect() = 0; // 순수 가상 함수로 선언
	Mouse() = default;
	virtual ~Mouse() = default; // 가상 소멸자
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

// 새로운 형태의 Mouse 추가 -> TrackballMouse
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