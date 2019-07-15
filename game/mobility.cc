#include "mobility.h"

using namespace std;

Mobility::Mobility(Hackmon & h) : hackmon{h} {}

bool Mobility::canMove() {
  return canMoveOverride();
}

bool Mobility::operator==(Mobility &other) {
  return name() == other.name();
}

Mobility::~Mobility() {}
