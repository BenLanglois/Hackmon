#include "mobility.h"

using namespace std;

Mobility::Mobility(Hackmon & h) : hackmon{h} {}

bool Mobility::canMove() const {
  return canMoveOverride();
}