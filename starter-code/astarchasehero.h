//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//ajayananth1
//Noah Hayden
//haydenn1


#ifndef ASTARCHASEHERO_H
#define ASTARCHASEHERO_H

#include "entitycontroller.h"
#include "maze.h"
#include "position.h"
#include "game.h"
#include "maze.h"

class AStarChaseHero : public EntityController {
private:
  // copy constructor and assignment operator are disallowed
  AStarChaseHero(const AStarChaseHero &);
  AStarChaseHero &operator=(const AStarChaseHero &);
  std::pair<int, Direction> tileTrace(Maze *gamemaze, Position tilepos, Position start, int dist);
  
public:
  AStarChaseHero();
  virtual ~AStarChaseHero();
 
  virtual Direction getMoveDirection(Game *game, Entity *entity);
  virtual bool isUser() const;
};

#endif // ASTARCHASEHERO_H
