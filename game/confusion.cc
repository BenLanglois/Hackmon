#include "confusion.h"
#include "statInfo.h"
#include "mobile.h"
#include "hackmon.h"

using namespace std;

Confusion::Confusion(Hackmon &h) : Mobility(h), rng{RandomGenerator(1,10)},
    damage{hackmon.stats.getMaxHP() / 10}, duration{5} {}


bool Confusion::canMoveOverride() {
  int currentHP = hackmon.stats.getStat(HP);
  // 60% chance damage will be inflicted
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

MobilityName Confusion::name() const {
  return CONFUSION;
}

unique_ptr<Mobility> Confusion::clone() const {
  return make_unique<Confusion>(*this);
}
