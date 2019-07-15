#include "stats.h"

using namespace std;

Stats::Stats(int maxHp, int baseAttack, int baseDefense, int baseSpeed) :
      maxHp{maxHp}, baseAttack{baseAttack}, baseDefense{baseDefense}, baseSpeed{baseSpeed},
      hp{maxHp}, attack{baseAttack}, defense{baseDefense}, speed{baseSpeed}, variance{5} {}
      
int Stats::getStat(StatName s) const {
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
      if (newValue > maxHp) {
        hp = maxHp;
      } else if (newValue < 0) {
        hp = 0;
      } else {
        hp = newValue;
      }
      break;
    case ATTACK:
      if(newValue > (baseAttack + variance)) {
        attack = baseAttack + variance;
      } else if (newValue < (baseAttack - variance)) {
        attack = baseAttack - variance;
      } else {
        attack = newValue;
      }
      break;
    case DEFENSE:
      if(newValue > (baseDefense + variance)) {
        defense = baseDefense + variance;
      } else if (newValue < (baseDefense - variance)) {
        defense = baseDefense - variance;
      } else {
        defense = newValue;
      }
      break;
    case SPEED:
      if(newValue > (baseSpeed + variance)) {
        speed = baseSpeed + variance;
      } else if (newValue < (baseSpeed - variance)) {
        speed = baseSpeed - variance;
      } else {
        speed = newValue;
      }
      break;
  }
}

int Stats::getMaxHP() const {
  return maxHp;
}
