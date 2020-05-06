//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "astarchasehero.h"
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>
#include "tile.h"

using std::vector; using std::string; 

AStarChaseHero::AStarChaseHero() {
}

AStarChaseHero::~AStarChaseHero() {
}

Direction AStarChaseHero::getMoveDirection(Game *game, Entity *entity) {
  Maze * gmaze = game->getMaze();
  
  vector<Entity*> heroes = game->getEntitiesWithProperty('h');
  vector<Position> hpos;
  for(vector<Entity*>::iterator it = heroes.begin(); it != heroes.end(); ++it) {
    hpos.push_back((*it)->getPosition());
  }

  //min_pos
  Position startpos = entity->getPosition();

  //Check if we start on hero
  for(vector<Position>::iterator iter = hpos.begin(); iter != hpos.end(); ++iter) {
    if(startpos == (*iter)) {
      return Direction::NONE;
    }
  }
  
  Position currpos = startpos;
  Direction closedir;
  int closedist = -1;

  //Loop through all heroes and do Astar algorithm to find shortest hero
  for(vector<Position>::iterator hposi = hpos.begin(); hposi != hpos.end(); ++hposi) { 
    float lowestf = -1;
    float fval;
    bool goalfound = false;
    bool alrexis = false;
    Tile * current = gmaze->getTile(currpos);
    current->setpos(currpos);
    vector<Position> openn;
    vector<Position> closen;
    openn.push_back(currpos);

    while(!goalfound) {  
      //Adds all the neighbors of current to openn
      for(Direction dir = Direction::UP; dir != Direction::NONE; ++dir) {
	const Position dispos  = currpos.displace(dir);
	Tile * checkent = gmaze->getTile(dispos);
	const string checkglyph = checkent->getGlyph();
	if (checkglyph[0] == '#') {
	  continue;
	}
	
	//Check if neighbor exists in openn and closed
	for (vector<Position>::iterator i = openn.begin(); i != openn.end(); ++i) {
	  if ((*i) == dispos) {
	    alrexis = true;
	  }
	}
	for (vector<Position>::iterator j = closen.begin(); j != closen.end(); ++j) {
	  if ((*j) == dispos) {
	    alrexis = true;
	  }
	}
	
	if(!alrexis) {
	  openn.push_back(dispos);

	  checkent->setpos(dispos);
	  checkent->setG(startpos);
	  checkent->setH(*hposi);
	  
	  //Sets parent as opposite direction
	  switch(dir) {
	  case Direction::UP: //UP
	    checkent->setPPos(Direction::DOWN);
	    break;
	  case Direction::DOWN: //DOWN
	    checkent->setPPos(Direction::UP);
	    break;
	  case Direction::LEFT: //LEFT
	    checkent->setPPos(Direction::RIGHT);
	    break;
	  case Direction::RIGHT: //RIGHT
	    checkent->setPPos(Direction::LEFT);
	    break;
	  case Direction::NONE:
	    break;
	  }
	} else if (alrexis) {
	  alrexis = false;
	  continue;
	}
      }      
      
      //remove this current from open
      //add old current to closed
      openn.erase(std::remove(openn.begin(), openn.end(), currpos), openn.end());
      closen.push_back(currpos);
      
      //Choose next current with lowest F (loop through all of open)
      for(vector<Position>::iterator h = openn.begin(); h != openn.end(); ++h) {
	Tile * checkt = gmaze->getTile(*h);
	fval = checkt->getF();
	
	//choose tile with lowest F
	if (lowestf == -1) {
	  lowestf = fval;
	  currpos = (*h);
	} else if (fval < lowestf) {
	  lowestf = fval;
	  currpos = (*h);
	}
      }
      current = gmaze->getTile(currpos);
      
      //If current is goal set isgoal to true
      if(currpos == (*hposi)) {
	goalfound = true;
      }
    }
  
    //Create loop to backtrace from the isgoal tile through the parents to get direction
    std::pair<int, Direction> p = tileTrace(gmaze, (*hposi), startpos, 0);
    if (closedist == -1) {
      closedist = p.first;
      closedir = p.second;
    } else if (p.first < closedist) {
      closedist = p.first;
      closedir = p.second;
    }
    //horizontal precedence over vertical movement
    if ((p.first == closedist) && ((p.second == Direction::RIGHT) || (p.second == Direction::LEFT))) {
      closedist = p.first;
      closedir = p.second;
    }
  }
  
  //return that direction
  return closedir;      
}

bool AStarChaseHero::isUser() const {
  return false;
}

//Pass in position of tiles under heroes
std::pair<int, Direction> AStarChaseHero::tileTrace(Maze *gamemaze, Position tilepos, Position start, int dist) {
  int distance = dist + 1;
  Direction pdir;
  Tile * curr = gamemaze->getTile(tilepos);
  Position prevpos = curr->getPPos();
  pdir = curr->getPDir();
  if (prevpos == start) {
    switch(pdir) {
    case Direction::UP: //UP
      return std::make_pair(distance, Direction::DOWN);
      break;
    case Direction::DOWN: //DOWN
      return std::make_pair(distance, Direction::UP);
      break;
    case Direction::LEFT: //LEFT
      return std::make_pair(distance, Direction::RIGHT);
      break;
    case Direction::RIGHT: //RIGHT
      return std::make_pair(distance, Direction::LEFT);
      break;
    case Direction::NONE:
      break;
    }
  }
  
  return tileTrace(gamemaze, prevpos, start, distance);
}

