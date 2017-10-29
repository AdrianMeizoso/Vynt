#include <vector>

class Player;

class World
{
public:
	World();
	~World();

	void tick();
	void executeCommand(std::vector<std::string>& args);

	Player* player;
};
