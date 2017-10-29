#include "creature.h"
#include <vector>

class Player : public Creature
{
public:
	Player(const char* title, const char* description, Room* room);
	~Player();

	void look(const std::vector<std::string>& args) const;
	void go(const std::vector<std::string>& args) const;
};
