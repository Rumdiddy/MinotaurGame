//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "uicontrol.h"
#include "ui.h"

//STUBS
UIControl::UIControl() {
}

UIControl::~UIControl() {
}

Direction UIControl::getMoveDirection(Game*, Entity*) {
  UI *ui = UI::getInstance();
  Direction dir = ui->getMoveDirection();
  return dir; 
}

bool UIControl::isUser() const {
  return true;
}
