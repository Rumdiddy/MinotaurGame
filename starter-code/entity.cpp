//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "entity.h"
#include "entitycontroller.h"
#include <string>
#include <cmath>

using std::string;

//constructor and destructor:
Entity::Entity() {
  gCost = -1;
  hCost = -1;
  fCost = -1;
}

Entity::~Entity() {
  delete parent_pos;
  delete m_pos;
  delete mcontroller;
}

//Sets parent position
void Entity::setPPos(int px, int py) {
  parent_pos = Position(px, py);
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

//Gets  position
void getchPos() const;


void Entity::setGlyph(const std::string &glyph) {
  mglyph = glyph; //should it be this->glyph ? 
}

void Entity::setProperties(const std::string &props) {
  mproperties = props; 
}

std::string Entity::getGlyph() const {
  return mglyph; 
}

std::string Entity::getProperties() const {
  return mproperties; 
}

bool Entity::hasProperty(char prop) const {
  std::size_t found = mproperties.find(prop);
  if (found == std::string::npos) {
    return false; 
  }
  return true; 
}

void Entity::setController(EntityController *controller) {
  mcontroller = controller; 
}

EntityController* Entity::getController() {
  return mcontroller; 
}

void Entity::setPosition(const Position &pos) {
  m_pos = pos; 
}

Position Entity::getPosition() const {
  return m_pos; 
}
