/*

	Aggregation ���� �ڵ�

	Aggregation�� Compositionó�� has-a ���踦 ��Ÿ�� �� ����Ѵ�.
	Aggregation�� Ŭ���� ���� �ٸ� Ŭ������ ��ü�� ��� ������ �����ϴ� �� ���, �����ͳ� ������ ���� �����ϴ� ������� �����Ѵ�.
	Aggregation�� ����ϸ� ��ü ���� ���踦 �����ϰ� ������ �� ������, �޸� ������ ���� å���� ��Ȯ�ϰ� �и��� �� �ִ�.
	Aggregation�� ���� ū Ư¡�� ���Ե� ��ü�� ���� �ֱⰡ �����ϴ� ��ü�� �������̶�� ���̴�. (�ڵ����� �Ҹ���� �ʴ´�)
	
	�� ���� �ڵ忡���� Pointer�� ����� Aggregation�� �ٷ��.

	Pointer�� ����� Aggregation�� ��	�� ��ü�� �ٸ� ��ü�� ������ ���ɼ��� �����ϴ� ��쿡 ����ϱ� �����ϴ�. (�ſ� ���� has-a ����)
*/

#include <iostream>

class Player
{
public:
	std::string name;

public:
	// Player ��ü�� ������
	Player(const std::string& name) : name(name)
	{
		std::cout << "Player created: " << name << std::endl;
	}
	// Player ��ü�� �Ҹ���
	~Player()
	{
		std::cout << "Player destroyed: " << name << std::endl;
	}
};

class Team
{
public:
	std::string teamName;

	// Team�� Player�� ������ ���� �ְ�, �������� ���� ���� �ִ�.
	// Aggregation�� ����Ͽ� Player ��ü�� �����ͷ� ����
	// �����͸� ���� �����ϴ� ��� nullptr�� �ʱ�ȭ�� �� �ִ�.
	Player* player = nullptr;

public:
	// Team ��ü�� ������
	Team(const std::string& teamName) : teamName(teamName)
	{
		std::cout << "Team created: " << teamName << std::endl;
	}
	// Team ��ü�� �Ҹ���
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
	// Player ��ü�� Team ��ü�� ���������� ���� �� �Ҹ�ȴ�.
	Player* player1 = new Player("Chae");
	
	// Team ��ü�� Player ��ü�� ���������� �������� ������ �ʴ´�.
	Team* teamA = new Team("Hanwha");
	teamA->setPlayer(player1);

	delete teamA; // Team ��ü�� �Ҹ�

	// Team�� �Ҹ�Ǿ Player ��ü�� ������ �����Ѵ�. (Team ��ü���� �������� ����)
	delete player1; // Player ��ü�� ������ �Ҹ���Ѿ� �Ѵ�.

	return 0;
}