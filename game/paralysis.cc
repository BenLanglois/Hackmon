#include "paralysis.h"

Paralysis::Paralysis(Hackmon & h) : Mobility(h), rng{RandomGenerator(1,2)} {}

bool Paralysis::canMoveOverride() {
  if(rng.getRandom() >= 7) {
    return true;
  } else {
    return false;
  }
}