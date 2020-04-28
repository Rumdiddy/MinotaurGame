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

bool Goal::isGoal() const {
  return true; 
}

MoveResult Goal::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const {
  return MoveResult::ALLOW;
}

std::string Goal::getGlyph() const {
  return "<"; 
}



