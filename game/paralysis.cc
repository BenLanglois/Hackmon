#include "paralysis.h"

Paralysis::Paralysis(Hackmon & h) : Mobility(h), rng{RandomGenerator(1,10)} {}

bool Paralysis::canMoveOverride() {
  return rng.getRandom() >= 7;
}

MobilityName Paralysis::name() const {
  return PARALYSIS;
}
