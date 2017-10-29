#include <iostream>
#include "game.h"
#include <Windows.h>

int main()
{
	std::cout << "VYNT\n\n";

	std::cout << "- Welcome to Vynt!\n"; 
	std::cout << "- Please, sit down\n";

	Game game;

	//game.AskDifficulty();
	//game.AskRole();

	std::cout << "- Excelent, your story are created!\n";
	std::cout << "- Please, enjoy your world\n\n";

	game.Inputloop();

	std::cout << "- Bye, come back son\n";
	Sleep(3000);

	return 0;
}