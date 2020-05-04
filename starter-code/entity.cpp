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
}

Entity::~Entity() {
  delete m_pos;
  delete mcontroller;
}


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
