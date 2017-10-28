#pragma once

class Game
{
public:
	Game();
	~Game();

	void AskDifficulty();
	void AskRole();
	void Inputloop();

private:
	int difficulty;
	int role;
};

