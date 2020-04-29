//floor cpp implementation file
//JHED: nhayden2, aananth3, sjin16

#include "floor.h"

using std::string;

//Default constructor:
Floor::Floor() {}

//Destructor
Floor::~Floor() {}

//returns ALLOW, because any entity can move onto a floor tile
MoveResult Floor::checkMoveOnto(Entity *, const Position &, const Position &) const {
  return MoveResult::ALLOW;
}

//returns false, because this is not the goal
bool Floor::isGoal() const {
  return false;
}

//. represents a floor space
std::string Floor::getGlyph() const {
  return ".";
}
