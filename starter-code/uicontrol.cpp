//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "uicontrol.h"

//STUBS
UIControl::UIControl() {
}

UIControl::~UIControl() {
}

Direction UIControl::getMoveDirection(Game*, Entity*) {
  Direction * stub = new Direction;
  return *stub;
}

bool UIControl::isUser() const {
  return true;
}
