//floor cpp implementation file
//JHED: nhayden2, aananth3, sjin16

#include "floor.h"

using std::string;

//Default constructor:
Floor::Floor() {}

//Destructor
Floor::~Floor() {}

//returns ALLOW, because any entity can move onto a floor tile
virtual MoveResult Floor::checkMoveOnto(Entity * entity, const Position &fromPos, const Position &tilePos) const {
  return 0;
}

//returns false, because this is not the goal
virtual bool Floor::isGoal() const {
  return 1;
}

//. represents a floor space
virtual string Floor::getGlyph() {
  return ".";
}
