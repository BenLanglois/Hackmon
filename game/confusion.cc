#include "confusion.h"

using namespace std;

Confusion::Confusion(Hackmon &h) : Mobility(h), rng{RandomGenerator(1, 2)} {
  damage = hackmon.stats.getMaxHP();
}

bool Confusion::canMoveOverride() const {
  // TO-DO: implement
}