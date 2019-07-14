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
    Stats(int, int, int, int);
    int getStat(StatName) const;
    void setStat(StatName, int);
    int getMaxHP() const;
};

#endif
