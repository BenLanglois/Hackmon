#ifndef STATS_H
#define STATS_H

#include "statInfo.h"

class Stats {
    const int maxHp;
    const int baseAttack;
    const int baseDefense;
    const int baseSpeed;
    int hp;
    int attack;
    int defense;
    int speed;
  public:
    Stats(const int mapHp, const int baseAttack, const int baseDefense, const int baseSpeed, int hp, int attack, int defense, int speed):
      maxHp{maxHp}, baseAttack{baseAttack}, baseDefense{baseDefense}, baseSpeed{baseSpeed}, hp{hp}, attack{attack},
      defense{defense}, speed{defense};
    const int getStat(StatName s) {
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
    void setStat(StatName s, int newValue) {
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
};

#endif
