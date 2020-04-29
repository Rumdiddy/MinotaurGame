//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "entity.h"
#include "entitycontroller.h"
#inclide <string>

using std::string;

//constructor and destructor:
Entity::Entity() {
  //TODO
}

Entity::~Entity() {
  //TODO
}

void Entity::setGlyph(const std::string &glyph) {
  glyph = glyph; //should it be this->glyph ? 
}

void Entity:setProperties(const std::string &props) {
  properties = props; 
}

std::string Entity::getGlyph() const {
  return glyph; 
}

std::string Entity:getProperties() const {
  return properties; 
}

bool Entity::hasProperty(char prop) const {
  std::size_t found = properties.find(prop);
  if (found == std::string::npos) {
    return false; 
  }
  return true; 
}

void Entity::setController(EntityController *controller) {
  controller = controller; 
}

EntityController* Entity::getController() {
  return controller; 
}

void Entity::setPosition(const Position &pos) {
  m_pos = pos; 
}

Position Entity::getPosition() const {
  return m_pos; 
}
