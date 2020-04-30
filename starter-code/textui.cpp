//Noah Hayden
//nhayden2
//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//aananth3

#include "textui.h"
#include <iostream>
#include <string>

using std::cout; using std::endl;

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
    return TextUI::getMoveDirection()
  }
  return choice;
}

// send a one-line message to be displayed the next time
// the render member function is called; if endgame parameter is
// true, it will be the last message displayed because the game
// is over 
void TextUI::displayMessage(const std::string &msg, bool endgame) {
  m_msg = msg;
}

// render the UI (draw maze and entities, any posted UI message)
void TextUI::render(Game* game) {
  //drawing the maze
  Maze* gmaze = game->getMaze();
  int cols = gmaze->getWidth(); int rows = gmaze->getHeight();
  for (int c < cols) {
    for (int r < rows) {
      Position curPos = Position(cols, rows);
      Tile* cur = gmaze->getTile(curPos);
      cout << cur->getGlyph;
    }
    cout << endl;
  }

  //printing any UI messages and clearing the field
  if (m_msg != "") {
    cout << m_msg << endl;
    m_msg.clear(); // clears msg field after printing
  }
} // still needs to handle cases where two entities are occupying the same space
