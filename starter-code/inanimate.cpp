//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "inanimate.h"

//STUBS
Inanimate::Inanimate() {
}

Inanimate::~Inanimate() {
}

Direction Inanimate::getMoveDirection(Game*, Entity*) {
  Direction * stub = new Direction;
  return *stub;
}

bool Inanimate::isUser() const {
  return true;
}
