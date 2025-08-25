/*

	Aggregation 예시 코드

	Aggregation은 Composition처럼 has-a 관계를 나타낼 때 사용한다.
	Aggregation은 클래스 내에 다른 클래스의 객체를 멤버 변수로 포함하는 것 대신, 포인터나 참조를 통해 연결하는 방식으로 구현한다.
	Aggregation을 사용하면 객체 간의 관계를 유연하게 관리할 수 있으며, 메모리 관리에 대한 책임을 명확하게 분리할 수 있다.
	Aggregation의 가장 큰 특징은 포함된 객체의 생명 주기가 포함하는 객체와 독립적이라는 점이다. (자동으로 소멸되지 않는다)
	
	본 예시 코드에서는 Pointer를 사용한 Aggregation을 다룬다.

	Pointer를 사용한 Aggregation은 어	떤 객체가 다른 객체를 포함할 가능성이 존재하는 경우에 사용하기 적합하다. (매우 약한 has-a 관계)
*/

#include <iostream>

class Player
{
public:
	std::string name;

public:
	// Player 객체의 생성자
	Player(const std::string& name) : name(name)
	{
		std::cout << "Player created: " << name << std::endl;
	}
	// Player 객체의 소멸자
	~Player()
	{
		std::cout << "Player destroyed: " << name << std::endl;
	}
};

class Team
{
public:
	std::string teamName;

	// Team은 Player을 포함할 수도 있고, 포함하지 않을 수도 있다.
	// Aggregation을 사용하여 Player 객체를 포인터로 연결
	// 포인터를 통해 연결하는 경우 nullptr로 초기화할 수 있다.
	Player* player = nullptr;

public:
	// Team 객체의 생성자
	Team(const std::string& teamName) : teamName(teamName)
	{
		std::cout << "Team created: " << teamName << std::endl;
	}
	// Team 객체의 소멸자
	~Team()
	{
		std::cout << "Team destroyed: " << teamName << std::endl;
	}

	void setPlayer(Player* player)
	{
		this->player = player;
	}
};

int main(void)
{
	// Player 객체는 Team 객체와 독립적으로 생성 및 소멸된다.
	Player* player1 = new Player("Chae");
	
	// Team 객체는 Player 객체를 포함하지만 소유권을 가지지 않는다.
	Team* teamA = new Team("Hanwha");
	teamA->setPlayer(player1);

	delete teamA; // Team 객체만 소멸

	// Team이 소멸되어도 Player 객체는 여전히 존재한다. (Team 객체에게 소유권이 없음)
	delete player1; // Player 객체는 별도로 소멸시켜야 한다.

	return 0;
}