//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//ajayananth1
//Noah Hayden
//haydenn1


#ifndef ASTARCHASEHERO_H
#define ASTARCHASEHERO_H

#include "entitycontroller.h"

class AStarChaseHero : public EntityController {
private:
  // copy constructor and assignment operator are disallowed
  AStarChaseHero(const AStarChaseHero &);
  AStarChaseHero &operator=(const AStarChaseHero &);
  std::pair<int, Direction> tileTrace(Game *game, Position tilepos, Position start, int dist);
  
public:
  AStarChaseHero();
  virtual ~AStarChaseHero();
 
  virtual Direction getMoveDirection(Maze *gamemaze, Entity *entity);
  virtual bool isUser() const;
};

#endif // ASTARCHASEHERO_H
