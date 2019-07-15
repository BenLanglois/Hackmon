#include "mobility.h"

using namespace std;

Mobility::Mobility(Hackmon & h) : hackmon{h} {}

bool Mobility::canMove() {
  return canMoveOverride();
}

Mobility::~Mobility() {}
