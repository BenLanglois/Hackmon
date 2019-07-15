#include "paralysis.h"

Paralysis::Paralysis(Hackmon & h) : Mobility(h), rng{RandomGenerator(1,10)} {}

bool Paralysis::canMoveOverride() {
  return rng.getRandom() >= 7;
    return true;
  } else {
    return false;
  }
}

MobilityName Paralysis::name() const {
  return PARALYSIS;
}
