//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "wall.h"

using std::string;

//Default constructor
Wall:Wall() {
}

//Destructor
Wall:~Wall() {
}

//Returns BLOCKED 
virtual MoveResult Wall:checkMoveOnto(Entity * entity, const Position &fromPos, const Position &tilePos) const {
  return 1;
}

//Returns false because not the goal
virtual bool Wall:isGoal() const {
  return 0;
}

//Walls are denoted by "#"
virtual string getGlyph() const {
  return "#";
}
