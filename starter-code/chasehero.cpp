//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "chasehero.h"
#include "entity.h"
#include <iterator>
#include <vector>
#include "game.h"
#include "maze.h"
#include "tile.h"

using std::string; using std::vector;

ChaseHero::ChaseHero() {
}

ChaseHero::~ChaseHero() {
}

Direction ChaseHero::getMoveDirection(Game *game, Entity *entity) {
  int lowestdist = -1;
  Direction lowestdir = Direction::NONE;
  Position epos = entity->getPosition();
  Maze * gmaze = game->getMaze();

  
  //Obtain positions of all heroes
  vector<Entity*> heroes = game->getEntitiesWithProperty('h');
  vector<Position> hpos;
  for(vector<Entity*>::iterator it = heroes.begin(); it != heroes.end(); ++it) {
    hpos.push_back((*it)->getPosition());
  }

  for(Direction dir = Direction::UP; dir != Direction::NONE; ++dir) {

    //Skip direction if not allowed
    const Position dispos = epos.displace(dir);
    const Tile * checkent = gmaze->getTile(dispos);
    const string checkglyph = checkent->getGlyph();
    if (checkglyph[0] == '#') {
      continue;
    }

    //Check for all heroes
    for (vector<Position>::iterator i = hpos.begin(); i != hpos.end(); ++i) {
      int distance = epos.distanceFrom(*i);
      if (lowestdist == -1) {
	lowestdist = distance;
	lowestdir = dir;
      } else if (distance < lowestdist) {
	lowestdist = distance;
	lowestdir = dir;
      } else if ((distance == lowestdist) && ((dir == Direction::RIGHT) || (dir == Direction::LEFT))) {
	lowestdir = dir;
      }     
    }
  }
  
  if (lowestdist == -1) {
    return Direction::NONE;
  } else {
    return lowestdir;
  }
}

bool ChaseHero::isUser() const {
  return false;
}
