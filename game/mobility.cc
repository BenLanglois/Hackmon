#include "mobility.h"

using namespace std;

bool Mobility::canMove() const {
  return canMoveOverride();
}