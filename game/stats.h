#ifndef STATS_H_
#define STATS_H_

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
    Stats(const int mapHp, const int baseAttack, const int baseDefense, const int baseSpeed):
      maxHp{maxHp}, baseAttack{baseAttack}, baseDefense{baseDefense}, baseSpeed{baseSpeed}, hp{mapHp}, attack{baseAttack},
      defense{baseDefense}, speed{baseSpeed};
    const int getStat(StatName s);
    void setStat(StatName s, int newValue);
};

#endif
