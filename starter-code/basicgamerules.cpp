//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2



virtual bool allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {


  Maze gameMaze = game -> getMaze();
  
  //TODO
  //Allows move if:
  //onto adjacent tile with 'v' property and that entity can also be moved OR
  //adjacent tile is empty

  //Check to make sure source and dest are adjacent
  bool oneJump = false; 
  int moveDir;
  
  for (int dir = UP; dir != NONE; dir++) {
    if (source.displace(dir) == dest) {
      oneJump = true;
      moveDir = dir; 
    }
  }
  if (oneJump == false) {
    return false; 
  }
  

  //remember, a entity is a character; either a hero or minotaur
  //and a tile is a goal/wall/floor
  Entity * destEntity = game -> getEntityAt(dest);
  Tile * destTile = game -> getTile(dest);
  
  //if  dest position is unoccupied & dest tile is able to be moved on
  if (destEntity == nullptr && destTile ->checkMoveResult(actor, source, dest) == ALLOW) {
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


virtual void enactMove(Game *game, Entity *actor, const Position &dest) const {

  //TODO

  actor -> setPosition(dest); 

  //just changes entity position
  //and also position of moved tile if applicable
}

virtual GameResult checkGameResult(Game *game) const {
   
  Maze* gameMaze = game -> getMaze();
  
  vector<Entity *> heroes = game -> getEntitiesWithProperty('h');
  vector<Entity *> minies = game -> getEntitiesWithProperty('m');
  //If any entity with the “h” property has reached a Goal tile, it should return GameResult::HERO_WINS
  for(vector<Entity *>::iterator it = heroes.begin();
      it != heroes.end();
      ++it) {
    if (gameMaze -> getTile(it -> getPosition()) ->isGoal()) {
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
      if (it -> getPosition() == it2 -> getPosition()) {
	return GameResult::HERO_LOSES;
      }
  }
  
  return GameResult::UNKNOWN;
}
