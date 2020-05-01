//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "chasehero.h"
#include <iterator>

using std::string;

ChaseHero::ChaseHero() {
}

ChaseHero::~ChaseHero() {
}

Direction ChaseHero::getMoveDirection(Game *game, Entity *entity) {
  int lowestdist = -1;
  int lowestdir = -1;
  Position epos = entity->getPosition()
  
  //Obtain positions of all heroes
  const vector<Entity*> heroes = game->getEntitiesWithProperty('h');
  const vector<Position> hpos;
  for(vector<Entity*>::iterator it = heroes.begin(); it != heroes.end; ++it) {
    hpos.push_back(it->getPosition());
  }

  for(int dir = UP; dir != NONE; dir++) {

    //Skip direction if not allowed
    const Position dispos = epos.displace(dir);
    Entity * checkent = game->getEntityAt(dispos);
    const string checkglyph = checkent->getGlyph();
    if (checkglyph == '#') {
      continue;
    }

    //Check for all heroes
    for (vector<Position>::iterator i = hpos.begin(); i != hpos.end; ++i) {
      int distance = epos.distanceFrom(i);
      if (lowest = -1) {
	lowestdist = distance;
	lowestdir = dir;
      } else if (distance < lowestdist) {
	lowestdist = distance;
	lowestdir = dir;
      } else if ((distance = lowestdist) && ((dir == 3) || (dir == 4))) {
	lowestdir = dir;
      }     
    }
  }
  
  if (lowestdist = -1) {
    return NONE;
  } else {
    return lowestdir;
  }
}

bool ChaseHero::isUser() const {
  return false;
}
