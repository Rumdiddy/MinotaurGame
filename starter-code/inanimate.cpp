//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "inanimate.h"
#include "position.h"

Inanimate::Inanimate() {
}

Inanimate::~Inanimate() {
}

Direction Inanimate::getMoveDirection(Game*, Entity*) {
  return Direction::NONE;
}

bool Inanimate::isUser() const {
  return false;
}
