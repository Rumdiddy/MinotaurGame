//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "tile.h"

Tile::Tile() {
}

Tile::~Tile() {
}

//Sets parent position
void Entity::setPPos(Direction dir) {
  parent_dir = dir;
  parent_pos = m_pos.displace(dir);
}

Position Entity::getPPos() {
  return parent_pos;
}

Direction Entity::getPDir() {
  return parent_dir;
}

//sets/gets hcost (GETS CLOSEST HERO)
void Entity::setH(Position chpos) {
  hCost = m_pos.distanceFrom(ch_pos);
}

float Entity::getH() const {
  return hCost;
}

//sets/gets gcost. Pass in minotaur position
void Entity::setG(Position min_pos) {
  gCost = m_pos.distanceFrom(min_pos);
}

float Entity::getG() const {
  return gCost;
}

//sets/gets fcost
float Entity::getF() const {
  fCost = hCost + gCost;
  return fCost;
}
