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

void Game::Inputloop()
{
	char key;
	std::string player_input;
	std::string anterior;
	int sol;
	std::vector<std::string> inputhistory;
	std::vector<std::string>::iterator it = inputhistory.end();
	std::vector<std::string>::reverse_iterator itRev = inputhistory.rbegin();
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
						if (player_input != "") {
							inputhistory.push_back(player_input);
							player_input = "";
						}
						else
						{
							inputhistory.push_back(" ");
						}
						
						if (it != inputhistory.begin()) {
							--it;
							++itRev;
							//if (!Same(*it, anterior)) {
								std::cout << "\n\n> ";
								std::cout << *it;
								anterior = *it;
							//}
						}
					}
					break;
				case KEY_DOWN: //Return
					if (!inputhistory.empty())
					{
						if (itRev != inputhistory.rbegin()) {
							++it;
							--itRev;
							//if (!Same(*it, anterior)) {
								std::cout << "\n\n> ";
								std::cout << *it;
								anterior = *it;
							//}
							
						}
					}
					break;
				}
				break;
			case '\r': //Return
				Tokenize(player_input, args);
				if (!player_input.empty()) {
					inputhistory.push_back(player_input);
					it = inputhistory.end();
					itRev = inputhistory.rbegin();
					--it;
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
