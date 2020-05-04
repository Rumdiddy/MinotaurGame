//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

//including needed classes
#include "game.h"
#include "maze.h"
#include "ui.h"
#include "position.h"
#include "entity.h"
#include "gamerules.h" 
#include "textui.h"

//constructor, destructor
Game::Game() {
}

Game::~Game() {
}

//set the maze object
void Game::setMaze(Maze* maze) {
  gmaze = maze;
}

//set the UI object
void Game::setUI(UI *ui) {
  gui = ui;
}

//set the Game rules object
void game::setGameRules(GameRules *gameRules) {
  grules = gameRules;
}

//add an entity to the sequence of entities
void Game::addEntity(Entity* entity) {
  gents->push_back(entity);
}

//helper function for getEntity at that takes a position and returns the type of entity at that position
Entity* Game::decodeEntity(const Tile* pos) {
  
}

//get the entity at the specified position
Entity* Game::getEntityAt(const Position &pos) {
  //access the maze vector and get the type of tile at that position
  //return the entity at the position based on the glyph
  Tile* cur = gmaze->getTile(pos);
  
}

//get the reference to the reference of pointers to entities
const EntityVec& Game::getEntities() const {
  return gents;
}

std::vector<Entity *> Game::getEntitiesWithProperty(char prop) const {
  //look for entities with given properties and add to vector:
  std::vector<Entity*> ents;
  Entity* cur = ents;
  while (cur != NULL) {
    if (cur->hasProperty(prop)) {
      ents.push_back(cur);
    }
    cur++;
  }
  return ents;
}

Maze* Game::getMaze() {
  return gmaze;
}

UI* Game::getUI() {
  return gui;
}

GameRules* Game::getGameRules() {
  return grules;
}

// Let the Entity objects take turns in round-robin fashion until
// the GameRules object determines that the hero has won or lost.
// Should call the render member function on the UI object just before
// an Entity whose EntityController is controlled by the user takes
// a turn.
void Game::gameLoop() {
  while (grules->checkGameResult(this) == GameResult::UNKNOWN) {
    //allowing each entity to take a turn
    for (size_t i = 0; i < EntityVec.size(); i++) {
      if (grules->checkGameResult(this) == GameResult::UNKNOWN) { 
	if (EntityVec[i]->getController()->isUser()) {
	  gui->render(this);
	}
	takeTurn(EntityVec[i]);
      }
    }
  }
  std::string msg;
  GameResult result = grules->checkGameResult(this);
  msg = (result == GameResult::HERO_WINS) ? "Hero wins" : "Hero loses";
  gui->displayMessage(msg, true);
}

// Let specified actor Entity take a turn.
// This is public so that it can be called from
// unit tests.  It is mainly intended to be called from
// the gameLoop member function.
void Game::takeTurn(Entity* actor) {
  
}

static Game* Game::loadGame(std::istream &in) {

}
