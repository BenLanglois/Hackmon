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
    int variance;
  public:
    Stats(const int, const int, const int, const int);
    const int getStat(StatName);
    void setStat(StatName, int);
};

#endif
