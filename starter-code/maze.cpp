//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3
//Noah Hayden
//nhayden2

#include "maze.h"

//Initializes maze with width * height tiles
Maze::Maze(int width, int height) {
  mwidth = width;
  mheight = height;  

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
  //TO DO

}

//Sets Tile at position. Maze must delete later
void Maze::setTile(const Position &pos, Tile *tile) {
  //TO DO
  
}

//Gets tile at specified position
const Tile Maze::*getTile(const Position & pos) const {
  //TO DO

}

// Read a description of Maze from specified istream and return it.
static Maze Maze::*read(std::istream &in) {
  //TO DO

}
  
