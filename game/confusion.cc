#include "confusion.h"
#include "statInfo.h"
#include "mobile.h"

using namespace std;

Confusion::Confusion(Hackmon &h) : Mobility(h), rng{RandomGenerator(1,10)}, 
    damage{hackmon.stats.getMaxHP() * 0.1}, duration{5} {}


bool Confusion::canMoveOverride() {
  int currentHP = hackmon.stats.getStat(HP);
  // 70% chance damage will be inflicted
  if(rng.getRandom() >= 5) {
    hackmon.stats.setStat(HP, currentHP - damage);
  }
  --duration;
  // continues until set duration
  if(duration == 0) {
    hackmon.mobility.reset(new Mobile(hackmon));
    return true;
  }
  return false;
};