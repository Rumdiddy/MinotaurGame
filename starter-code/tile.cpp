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
void Tile::setPPos(Direction dir) {
  parent_dir = dir;
  parent_pos = m_pos.displace(dir);
}

Position Tile::getPPos() {
  return parent_pos;
}

Direction Tile::getPDir() {
  return parent_dir;
}

//sets/gets hcost (GETS CLOSEST HERO)
void Tile::setH(Position chpos) {
  hCost = m_pos.distanceFrom(ch_pos);
}

float Tile::getH() const {
  return hCost;
}

//sets/gets gcost. Pass in minotaur position
void Tile::setG(Position min_pos) {
  gCost = m_pos.distanceFrom(min_pos);
}

float Tile::getG() const {
  return gCost;
}

//sets/gets fcost
float Tile::getF() const {
  fCost = hCost + gCost;
  return fCost;
}
