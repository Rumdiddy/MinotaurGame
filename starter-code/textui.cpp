//Noah Hayden
//nhayden2
//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3

#include "textui.h"
#include <iostream>
#include <string>
#include "maze.h"
#include "game.h"
#include "tile.h"

using std::cout; using std::endl;
using std::cin;

TextUI::TextUI() {

}

TextUI:: ~TextUI() {

}

Direction TextUI::getMoveDirection() {
  char moveChoice; Direction choice;
  cout << "Your move (u/d/l/r): ";
  cin >> moveChoice;
  switch (moveChoice) {
  case 'u':
    choice = Direction::UP; break;
  case 'd':
    choice = Direction::DOWN; break;
  case 'l':
    choice = Direction::LEFT; break;
  case 'r':
    choice = Direction::RIGHT; break;
  default:
    cout << "Unknown direction" << endl;
    return TextUI::getMoveDirection();
  }
  return choice;
}

// send a one-line message to be displayed the next time
// the render member function is called; if endgame parameter is
// true, it will be the last message displayed because the game
// is over 
void TextUI::displayMessage(const std::string &msg, bool) {
  m_msg = msg;
}

// render the UI (draw maze and entities, any posted UI message)
void TextUI::render(Game* game) {
  //drawing the maze
  Maze* gmaze = game->getMaze();
  int cols = gmaze->getWidth(); int rows = gmaze->getHeight();
  int c = 0;
  int r = 0;
  GameRules * gr = game->getGameRules();
  bool gamelost = false;
  if (gr->checkGameResult(game) == GameResult::HERO_LOSES) {
    gamelost = true;
  }

  std::vector<Entity*> aents = game->getEntitiesWithProperty('h');
  std::vector<Entity*> mino = game->getEntitiesWithProperty('m');
  Position losthero;
  
  if (gamelost) {
    bool lostherofound = false;
    for (std::vector<Entity*>::iterator iter = aents.begin(); iter != aents.end(); ++iter) {
      for (std::vector<Entity*>::iterator iter2 = mino.begin(); iter2 != mino.end(); ++iter2) {
	if ((*iter)->getPosition() == (*iter2)->getPosition()) {
	  losthero = (*iter)->getPosition();
	  lostherofound = true;
	  break;
	}
      }
      if (lostherofound) {
	break;
      }
    }
  }

  

  while (r < rows) {
    while (c < cols) {
      bool match = false;
      //find if there is an entity on the tile
      std::vector<Entity*> ents = game->getEntities();
      Position curPos = Position(c, r);

      if (gamelost && (losthero == curPos)) {
	for (std::vector<Entity*>::iterator iter3 = mino.begin(); iter3 != mino.end(); ++iter3) {
	  if ((*iter3)->getPosition() == losthero && (*iter3)->getPosition() == curPos) {
	    cout << (*iter3)->getGlyph();
	    match = true;
	  }
	}
      } else {
	for (size_t i = 0; i < ents.size(); i++) {
	  
	  //checking whether there is an entity occupying the tile
	  if (ents[i]->getPosition().getX() == curPos.getX() && ents[i]->getPosition().getY() == curPos.getY()) {
	    cout << ents[i]->getGlyph();
	    match = true;
	  }
	}
      }
      if (match == false) {
	Tile* cur = gmaze->getTile(curPos);
	cout << cur->getGlyph();
      }
      c++;
    }
    c = 0;
    cout << endl;
    r++;
  }

  //printing any UI messages and clearing the field
  if(m_msg != "") {
    cout << m_msg << endl;
    m_msg.clear(); // clears msg field after printing
  }
}
