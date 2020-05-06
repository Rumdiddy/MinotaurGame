//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "game.h"
#include "ecfactory.h"
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>

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
void Game::setGameRules(GameRules *gameRules) {
  grules = gameRules;
}

//add an entity to the sequence of entities
void Game::addEntity(Entity* entity) {
  gents.push_back(entity);
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
  //search the entities for the entity with the specified position
  //if not, return that there is no entity
  std::vector<Entity*>::const_iterator it;
  for (it = this->gents.cbegin(); it != this->gents.cend(); ++it) {
    if ((*it)->getPosition() == pos) {
      return *it;
    }
  }
  return NULL;
}

std::vector<Entity *> Game::getEntitiesWithProperty(char prop) {
  //look for entities with given properties and add to vector:
  std::vector<Entity *> ents1;
  //for (std::vector<Entity*>::const_iterator it = gents.cbegin(); it != gents.cend(); ++it) {
  for (size_t i = 0; i < gents.size(); ++i) {
    if (gents[i]->hasProperty(prop)) {
      ents1.push_back(gents[i]);
    }
  }
  return ents1;
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
  EntityVec ents = this->getEntities();
  while (grules->checkGameResult(this) == GameResult::UNKNOWN) {
    //allowing each entity to take a turn
    for (size_t i = 0; i < ents.size(); i++) {
      if (grules->checkGameResult(this) == GameResult::UNKNOWN) { 
	if (ents[i]->getController()->isUser()) {
	  gui->render(this);
	}
	takeTurn(ents[i]);
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
  Position source = actor->getPosition();
  Position dest = source.displace(mv);
  bool legality = grules->allowMove(this, actor, source, dest);
  if (!legality) {
    //enact move, otherwise ask for new move
    if (actor->getController()->isUser()) {
      gui->displayMessage("Illegal Move", false);
    }
    //takeTurn(actor);
  } else {
    grules->enactMove(this, actor, dest);
  }
}

Game* Game::loadGame(std::ifstream &in) {
  //read in maze
  Maze* gmaze = Maze::read(in);
  if (gmaze == NULL) { return NULL; }
  Game* g = new Game();
  int cols = gmaze->getWidth();
  //int rows = gmaze->getHeight();
  char c; char entcontroller; std::string glyph; int x, y; std::string props;
  EntityControllerFactory *ecf;
  ecf = ecf->getInstance();
  x = 0;
  y = 0;
  int count = 0;
  in.clear();
  in.seekg(0);
  in >> x; in >> y;
  while (in >> c) {
    glyph = c;
    in >> entcontroller;
    x = count % cols;
    y = count / cols;
    count++;
    
    Entity* ent = new Entity();
    Position pos = Position(x, y);
    ent->setPosition(pos);
    ent->setGlyph(glyph);

    if (glyph == "@") {
      props = "@uh";
      ent->setProperties(props);
    } else if (glyph == "M") {
      props = "Mcm";
      ent->setProperties(props);
    }
    
    EntityController * econtroller = ecf->createFromChar(entcontroller);
    ent->setController(econtroller);
    //set proper controller here based on the character in properties
    g->addEntity(ent);
  }
  g->setMaze(gmaze);
  return g;
}

//get the reference to the reference of pointers to entities
const std::vector<Entity*>& Game::getEntities() const {
  return gents;
}
