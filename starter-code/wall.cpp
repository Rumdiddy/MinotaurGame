//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "wall.h"

using std::string;

//Default constructor
Wall::Wall() {
}

//Destructor
Wall::~Wall() {
}

//Returns BLOCKED 
MoveResult Wall::checkMoveOnto(Entity * entity, const Position &fromPos, const Position &tilePos) const {
  return MoveResult::BLOCK;
}

//Returns false because not the goal
bool Wall::isGoal() const {
  return 0;
}

//Walls are denoted by "#"
string Wall::getGlyph() const {
  return "#";
}
