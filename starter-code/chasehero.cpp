//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "chasehero.h"

//STUBS
ChaseHero::ChaseHero() {
}

ChaseHero::~ChaseHero() {
}

Direction ChaseHero::getMoveDirection(Game*, Entity*) {
  Direction * stub = new Direction;
  return *stub;
}

bool ChaseHero::isUser() const {
  return true;
}
