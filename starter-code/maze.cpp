//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "maze.h"
#include "tile.h"
#include "position.h"
#include "tilefactory.h"
#include <iterator>

//Initializes maze with width * height tiles
Maze::Maze(int width, int height) : mwidth(width), mheight(height) {
}

//Deletes all tiles and sets width and height to 0
Maze::~Maze() {
  mwidth = 0;
  mheight = 0;
  for(int i = 0; i < (mwidth * mheight); ++i) {
    delete mazeVec[i];
  }
  //delete this; segmentation fault disappears when this is removed from code
}

//Gets width of Maze
int Maze::getWidth() const {
  return mwidth;
}

//Gets height of Maze
int Maze::getHeight() const {
  return mheight;
}

//Return true if position is in bounds (width and height)
bool Maze::inBounds(const Position &pos) const {
  if (pos.getX() >= mwidth || pos.getY() >= mheight) {
    return false;
  }
  return true;
}

//Sets Tile at position. Maze must delete later
void Maze::setTile(const Position &pos, Tile *tile) {
  int p = pos.getX() + pos.getY() * mwidth;
  mazeVec[p] = tile; 
}

//Gets tile at specified position
Tile* Maze::getTile(const Position & pos) const {
  int p = pos.getX() + pos.getY() * mwidth;
  return mazeVec[p];
}

// Read a description of Maze from specified istream and return it.
Maze* Maze::read(std::istream &in) {
  
  int width; int height;
  in >> width; in >> height;
  Maze* nmaze = new Maze(width, height);

  //reading in maze tiles and copying to the maze vector of tiles
  int count = 0;
  char c;
  TileFactory* factory = TileFactory::getInstance();

  while (in >> c) {
    Tile* insert = factory->TileFactory::createFromChar(c);
    nmaze->mazeVec.push_back(insert);
    count++;
  }

  return nmaze;
}
  
