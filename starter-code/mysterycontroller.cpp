//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//ajayananth1
//Noah Hayden
//haydenn1

#include "mysterycontroller.h"

MysteryController::MysteryController() {
}

MysteryController::~MysteryController() {
}

Direction MysteryController::getMoveDirection(Game *, Entity *) {
  return Direction::NONE;
}

bool MysteryController::isUser() const {
  return false;
}
