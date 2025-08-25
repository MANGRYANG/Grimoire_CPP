/*

	Aggregation ���� �ڵ�

	Aggregation�� Compositionó�� has-a ���踦 ��Ÿ�� �� ����Ѵ�.
	Aggregation�� Ŭ���� ���� �ٸ� Ŭ������ ��ü�� ��� ������ �����ϴ� �� ���, �����ͳ� ������ ���� �����ϴ� ������� �����Ѵ�.
	Aggregation�� ����ϸ� ��ü ���� ���踦 �����ϰ� ������ �� ������, �޸� ������ ���� å���� ��Ȯ�ϰ� �и��� �� �ִ�.
	Aggregation�� ���� ū Ư¡�� ���Ե� ��ü�� ���� �ֱⰡ �����ϴ� ��ü�� �������̶�� ���̴�. (�ڵ����� �Ҹ���� �ʴ´�)
	�� ���� �ڵ忡���� Pointer�� ����� Aggregation�� �ٷ��.

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

	// Aggregation�� ����Ͽ� Player ��ü�� �����ͷ� ����
	Player* player;

public:
	// Team ��ü�� ������
	Team(const std::string& teamName, Player* player) : teamName(teamName), player(player)
	{
		std::cout << "Team created: " << teamName << " with player " << player->name << std::endl;
	}
	// Team ��ü�� �Ҹ���
	~Team()
	{
		std::cout << "Team destroyed: " << teamName << std::endl;
	}

};

int main(void)
{
	// Player ��ü�� Team ��ü�� ���������� ���� �� �Ҹ�ȴ�.
	Player* player1 = new Player("Chae");
	
	// Team ��ü�� Player ��ü�� �������� �ʰ�, ���� ������ �Ѵ�.
	Team* teamA = new Team("Hanwha", player1);

	delete teamA; // Team ��ü�� �Ҹ�

	// Team�� �Ҹ�Ǿ Player ��ü�� ������ �����Ѵ�.
	delete player1; // Player ��ü�� ������ �Ҹ���Ѿ� ��

	return 0;
}