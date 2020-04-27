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

//Initializes maze with width * height tiles
Maze::Maze(int width, int height) : mwidth(width), mheight(height) {
  std::vector<Tile*> array;
  mazeVec = array; 
  //TO DO: set tiles?
  
}

//Deletes all tiles and sets width and height to 0
Maze::~Maze() {
  mwidth = 0;
  mheight = 0;

  //TO DO: clear all tiles
  
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
const Tile* Maze::getTile(const Position & pos) const {
  int p = pos.getX() + pos.getY() * mwidth;
  return mazeVec[p];
}

// Read a description of Maze from specified istream and return it.
Maze* Maze::read(std::istream &in) {
  //TO DO
  int width; int height;
  in >> width; in >> height;
  Maze* newMaze = new Maze(width, height);
  //reading in maze tiles and copying to the maze vector of tiles
  int count = 0;
  char c;
  TileFactory* factory = TileFactory::getInstance();
  while (in >> c) {
    //check for the type of tile and add accordingly
    if (c == '#') {
      //allocate this type of tile in to the array
      Tile* insert = factory->TileFactory::createFromChar(c);
      mazeVec.push_back(insert);
    }
    else if (c == '.') {
      Tile* insert = factory->TileFactory::createFromChar(c);
      mazeVec.push_back(insert);
    }
    else if (c == '<') {
      Tile* insert = factory->TileFactory::createFromChar(c);
      mazeVec.push_back(insert);
    }
    count++;
  }

  return newMaze;
}
  
