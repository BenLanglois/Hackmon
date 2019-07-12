#include "stats.h"

using namespace std;

const int Stats::getStat(StatName s) {
  switch(s) {
    case HP:
      return hp;
    case ATTACK:
      return attack;
    case DEFENSE:
      return defense;
    case SPEED:
      return speed;
  }
}

void Stats::setStat(StatName s, int newValue) {
  switch(s) {
    case HP:
      hp = newValue;
      break;
    case ATTACK:
      attack = newValue;
      break;
    case DEFENSE:
      defense = newValue;
      break;
    case SPEED:
      speed = newValue;
      break;
  }
}