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

MoveResult Goal::checkMoveOnto(Entity *, const Position &, const Position &) const {
  return MoveResult::ALLOW;
}

std::string Goal::getGlyph() const {
  return "<"; 
}



