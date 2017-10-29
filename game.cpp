#include <iostream>
#include "game.h"
#include "globals.h"
#include <conio.h>
#include <string>
#include <vector>
#include <list>

Game::Game()
{
}


Game::~Game()
{
}

void Game::AskDifficulty()
{
	std::cout << "Watch out! Your future will change with your choice\n\n";
	std::cout << "1. Walk\n";
	std::cout << "2. Run\n\n";

	std::cin >> difficulty;

	if (difficulty == 1) {
		std::cout << "\nGood choice\n";
	}
	else if (difficulty == 2)
	{
		std::cout << "\nHard one\n";
	}
	else
	{
		difficulty = 2;
		std::cout << "\nNot choosing is an option\n";
	}
}

void Game::AskRole()
{
	std::cout << "\nEach one makes himself\n\n";
	std::cout << "1. Stone\n";
	std::cout << "2. Feather\n\n";

	std::cin >> role;
}

void erase() {
	std::cout << '\b';
	std::cout << " ";
	std::cout << '\b';
}

void erase(int characters) {
	for (int i = 0; i < characters; i++)
	{
		erase();
	}
}

void Game::Inputloop()
{
	char key;
	std::string player_input;

	std::string anterior = "";
	std::vector<std::string> inputhistory;
	int it = inputhistory.size();


	std::vector<std::string> args;
	args.reserve(10);

	args.push_back("look");

	while (1) {

		if (_kbhit())
		{
			key = _getch();
			switch (key) {
			case '\b': //Backspace
				if (player_input.length() > 0)
				{
					player_input.pop_back();
					erase();
				}
				break;
			case-32: 
				switch (_getch()) {
				case KEY_UP: //Return
					if (!inputhistory.empty())
					{
						if (it < inputhistory.size())
						{
							erase(anterior.length());
							if (it > 0) --it;
							anterior = inputhistory[it];
						}

						if (it == inputhistory.size())
						{
							erase(player_input.length());
							anterior = inputhistory[it - 1];
							if (it > 0) --it;
						}
						
						std::cout << inputhistory[it];
					}
					break;
				case KEY_DOWN: //Return
					if (!inputhistory.empty())
					{
						if (it < inputhistory.size() - 1) {
							erase(anterior.length());
							
							++it;
							anterior = inputhistory[it];
							//if (!Same(*it, anterior)) {
							//}

							std::cout << inputhistory[it];
						}
						else {
							erase(anterior.size());
							anterior = player_input;
							std::cout << player_input;
							it = inputhistory.size();
						}

					}
					break;
				}
				break;
			case '\r': //Return
				Tokenize(player_input, args);
				if (!player_input.empty()) {
					inputhistory.push_back(player_input);
					it = inputhistory.size();
				}
				std::cout << "\n";
				break;
			case 27: //Escape
				std::cout << "\nYou cannot escape your destiny\n";
				std::cout << "\n> ";
				break;
			default:
				player_input += key;
				std::cout << key;
			}
		}

		if (args.size() > 0 && Same(args[0], "quit"))
			break;

		if (args.size() > 0)
		{
			args.clear();
			player_input = "";
			std::cout << "\n> ";
		}
	}
}
