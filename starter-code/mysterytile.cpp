//Samuel Jin
//sjin16
//Ajay Ananthakrishnan
//ajayananth1
//Noah Hayden
//haydenn1

#include "mysterytile.h"

MysteryTile::MysteryTile() {
}

MysteryTile::~MysteryTile() {
}

MoveResult MysteryTile::checkMoveOnto(Entity *, const Position &, const Position &) const {
  return MoveResult::ALLOW;
}

bool MysteryTile::isGoal() const {
  return false;
}

std::string MysteryTile::getGlyph() const {
  return "?";
}
