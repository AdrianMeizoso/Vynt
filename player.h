#include "creature.h"
#include <vector>

class Player : public Creature
{
public:
	Player(const char* title, const char* description, Room* room);
	~Player();

	void look(const std::vector<std::string>& args) const;
	void go(const std::vector<std::string>& args);
	void examine(const std::vector<std::string>& args);
	void inventory() const;
	void take(const std::vector<std::string>& args);
	void drop(const std::vector<std::string>& args);

};
