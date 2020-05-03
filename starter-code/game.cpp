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

//get the entity at the specified position
Entity* Game::getEntityAt(const Position &pos) {
  //access the maze vector and get the type of tile at that position
  //return the entity at the position based on the glyph
  
}

//get the reference to the reference of pointers to entities
const EntityVec& Game::getEntities() const {

}

std::vector<Entity *> Game::getEntitiesWithProperty(char prop) const {

}

Maze* Game::getMaze() {

}

UI* Game::getUI() {

}

GameRules* Game::getGameRules() {

}

void Game::gameLoop() {

}

void Game::takeTurn(Entity* actor) {

}

static Game* Game::loadGame(std::istream &in) {

}
