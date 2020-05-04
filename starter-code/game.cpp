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
/*
Entity* Game::decodeEntity(const Tile* pos) {
  
}
*/

//get the entity at the specified position
Entity* Game::getEntityAt(const Position &pos) {
  //access the maze vector and get the type of tile at that position
  //return the entity at the position based on the glyph
  Tile* cur = gmaze->getTile(pos);
  //search the entities for the entity with the specified position
  //if not, return that there is no entity
  std::vector<Entity*>::const_iterator it;
  for (it = this.gents->cbegin(); it != this.gents->cend(); ++it) {
    if (it->getPosition() == pos) {
      return it;
    }
  }
  return NULL;
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
  //getting suggested move
  Direction mv = actor->getController()->getMoveDirection(this, actor);
  
  //checking according to game rules
  Position source = actor->getPosition;
  Position dest = Position::displace(mv);
  bool legality = grules->allowMove(this, actor, source, dest);
  if (legality) {
    //enact move, otherwise ask for new move
    grules->enactMove(this, actor, dest);
  }
  gui->displayMessage("Illegal Move", false);
  takeTurn(actor);
}

static Game* Game::loadGame(std::istream &in) {
  //read in maze
  Maze* gmaze = new Maze();
  Game* g = new Game();
  gmaze = Maze::read(std::istream& in);
  char c; char entcontroller; char glyph; int x, y;
  while (in >> c) {
    glyph = c;
    in >> entcontroller;
    while (c != ' ') {
      in >> prop;
      props += prop;
    }
    in >> x; in >> y;
    Entity* ent = new Entity();
    Position pos = new Position(x, y);
    ent->setPos(pos);
    ent->setGlyph(glyph);
    ent->setProperties(props);
    ent->setController(entcontroller);
    g->addEntity(ent);
  }
  g->setMaze(gmaze);
  return g;
}
