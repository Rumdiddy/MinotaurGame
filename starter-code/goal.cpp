//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "goal.h"

Goal::Goal() {
}

Goal::~Goal() {
}

bool Goal::isGoal() {
  return true; 
}

virtual MoveResult Goal::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const {
  reutrn (void)MoveResult::ALLOW;
}

std::string Goal::getGlyph() {
  return "<"; 
}



