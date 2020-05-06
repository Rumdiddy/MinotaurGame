//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "basicgamerules.h"
#include "maze.h"
#include "game.h"
#include "position.h"
#include "tile.h"
#include <vector>

using std::vector; 

BasicGameRules::BasicGameRules() { }

BasicGameRules::~BasicGameRules() { }

bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {


  Maze* gameMaze = game -> getMaze();
  
  //TODO
  //Allows move if:
  //onto adjacent tile with 'v' property and that entity can also be moved OR
  //adjacent tile is empty

  //Check to make sure source and dest are adjacent
  bool oneJump = false; 
  Direction moveDir;
  


  for(Direction dir = Direction::UP; dir <= Direction::NONE; ++dir) {
    if (source.displace(dir) == dest) {
      oneJump = true;
      moveDir = dir; 
    }
  }
  if (oneJump == false) {
    return false; 
  }
  
  //
  //remember, a entity is a character; either a hero or minotaur
  //and a tile is a goal/wall/floor
  Entity * destEntity = game -> getEntityAt(dest);
  Tile * destTile = gameMaze -> getTile(dest);
  
  //if  dest position is unoccupied & dest tile is able to be moved on
  if (destEntity == nullptr && destTile ->checkMoveOnto(actor, source, dest) == MoveResult::ALLOW) {
    return true; 
  }
  else if (destEntity -> hasProperty('v')) {
    if (game -> getEntityAt(dest.displace(moveDir)) ==nullptr) {
      return true; 
    }
  }
  //if above cases not reached, 
  return false; 
}


void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {
  
  Position curPosition = actor -> getPosition(); 
  
  //find push direction
  Direction moveDir;

  for (Direction dir = Direction::UP; dir <= Direction::NONE; ++dir) {
    if (curPosition.displace(dir) == dest) {
	    moveDir = dir;
      }
  }
  
  Position adjacPos = curPosition.displace(moveDir); 
  Entity * adjacEnt = game -> getEntityAt(adjacPos);
  //if there is a moveable entity adjacent, move both entity and that property
  if (adjacEnt != nullptr) {
      adjacEnt ->setPosition(adjacPos.displace(moveDir)); 
      actor -> setPosition(dest); 
    }
  //else, just move the actor by 1 unit in the push direction
  else {
      actor -> setPosition(dest); 
    }
}

GameResult BasicGameRules::checkGameResult(Game *game) const {

  Maze * gameMaze = game -> getMaze();

  vector<Entity *> heroes = game -> getEntitiesWithProperty('h');
  vector<Entity *> minies = game -> getEntitiesWithProperty('m');
  //If any entity with the “h” property has reached a Goal tile, it should return GameResult::HERO_WINS
  for(vector<Entity *>::iterator it = heroes.begin();
      it != heroes.end();
      ++it) {
    if (gameMaze -> getTile((*it) -> getPosition()) ->isGoal()) {
      return GameResult::HERO_WINS; 
    } 
  }

  //If any entity with the “m” property occupies a position where an entity with the “h” property is located, it should return GameRules::HERO_LOSES
  for(vector<Entity *>::iterator it = minies.begin();
      it != minies.end();
      ++it) {
    for(vector<Entity *>::iterator it2 = heroes.begin();
	it2 != heroes.end();
	++it2)
      if ((*it) -> getPosition() == (*it2) -> getPosition()) {
	return GameResult::HERO_LOSES;
      }
  }
  
  return GameResult::UNKNOWN;
}
