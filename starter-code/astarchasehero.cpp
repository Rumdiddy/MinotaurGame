//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "astarchasehero.h"
#include <iterator>

AStarChaseHero::AStarChaseHero() {
}

AStarChaseHero::~AStarChaseHero() {
}

Direction AStarChaseHero::getMoveDirection(Game *game, Entity *entity) {
  
  Maze * gmaze = game->getMaze();
  const vector<Entity*> heroes = game->getEntitiesWithProperty('h');
  const vector<Position> hpos;
  for(vector<Entity*>::iterator it = heroes.begin(); it != heroes.end(); ++it) {
    hpos.push_back(it->getPosition());
  }

  //const mazeVec allent = gmaze->getEntities();

  //min_pos
  Position startpos = entity->getPosition();
  vector<Position> openn;
  vector<Position> closen;
  Entity current = game->getEntityAt(startpos);
  
  openn.push_back(startpos);
  bool goalfound = false;
  bool alrexis = false;
  
  
  while(!goalfound) {

    //Adds all the neighbors of current to openn
    for(int dir = UP; dir != NONE; dir++) {
      const Position dispos = current.getPosition();
      dispos = dispos.displace(dir);
      Tile * checkent = game->getTile(dispos);
      const string checkglyph = checkent->getGlyph();
      if (checkglyph == '#') {
	continue;
      }

      //Check if neighbor exists
      for (vector<Position>::iterator i = openn.begin(); i != heroes.end(); ++i) {
	if (i == dispos) {
	  alrexis = true;
	}
      }

      if(!alrexis) {
	openn.push_back(dispos);

	checkent->setG(startpos);
	checkent->setH(hpos[0]);
       
	//Sets parent as opposite direction
	switch(dir) {
	case 1: //UP
	  checkent->setPPos(DOWN);
	  break;
	case 2: //DOWN
	  checkent->setPPos(UP);
	  break;
	case 3: //LEFT
	  checkent->setPPos(RIGHT);
	  break;
	case 4: //RIGHT
	  checkent->setPPos(LEFT);
	  break;
	}
      }
    }      
    
      
	  
	
    
  
  
}

bool AStarChaseHero::isUser() const {
  return false;
}

