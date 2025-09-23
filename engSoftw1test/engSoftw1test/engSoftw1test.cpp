#include <iostream>
#include <fstream>
#include <string>


class Player
{
public:

	std::string name;
	int hp;
	int atk;
	bool friendly;

	Player()
		:name("");

};


Player* creatrePlayer(std::string path)
{
	std::ifstream inputStream;
	inputStream.open(path);

	std::string word1;
	std::string word2 = "";

	Player* player = new Player;

	if (inputStream.is_open())
	{
		

		while (std::getline(inputStream, word1))
		{
			std::cout << word1 << std::endl;

			if (word2[0] == '"')
			{
				std::cout << "si" << std::endl;

				if (word2[1] == 'n')
				{
					player->name = word1;
				}
			}

				word2 = word1;
		}

		std::cout << player->name;

	}
	else
	{
		std::cout << "not open";
	}

	return player;
}

int main()
{
	Player* player1;
	
	player1 = creatrePlayer("player1.txt");
}