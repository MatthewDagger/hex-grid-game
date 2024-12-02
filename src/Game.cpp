#include <queue>
#include <vector>
#include <unordered_set>
#include "Game.hpp"

Game::Game(TileMap& map): map(map) {}

void Game::step(){

}


void Game::move_unit(Unit* unit, Hex& destination) {
	std::list<Hex> path = generate_path(unit->get_location(), destination);

}

// Use A* algorithm to find the fastest path to the destination
std::list<Hex> Game::generate_path(Hex& origin, Hex& destination) {
	std::unordered_map<Hex, int> travel_dists;
	travel_dists.insert_or_assign( origin, 0 );

	std::unordered_map<Hex, Hex> parents;
	CompareHexDistance comparator = CompareHexDistance(destination, travel_dists);
	std::priority_queue<Hex, std::vector<Hex>, CompareHexDistance> open_list(comparator);
	std::unordered_set<Hex> closed_list;

	// Initialise list
	open_list.push(origin);
	while (!open_list.empty()) {
		Hex current = open_list.top();
		open_list.pop();

		// Check for destination
		if (current == destination)
		{
			std::list<Hex> path;
			while (current != origin)
			{
				path.push_back(current);
				current = parents.at(current);
			}

			return path;
		}

		// Close current hex
		closed_list.insert(current);

		// Explore Neighbours
		for (int i = 0; i < 6; ++i) {
			Hex neighbour = current.get_neighbour(i);

			// Check if neighbour is in map
			if (!map.tiles.count(neighbour)) {
				continue;
			}

			// TODO: Check if neighbour is walkable
			//if (!map.tiles.count(neighbour)) {
			//	continue;
			//}

			// Check if nieghbour is in closed list
			if (closed_list.count(neighbour)) {
				continue;
			}

			int travelDist = travel_dists.at(current) + 1;
			if (!(travel_dists.count(neighbour)) || travel_dists.at(neighbour) > travelDist) {
				travel_dists.insert_or_assign(neighbour, travelDist);
				open_list.push(neighbour);
				parents.insert_or_assign(neighbour, current);
			}

		}


	}

	// No path found
	return std::list<Hex>();
}
