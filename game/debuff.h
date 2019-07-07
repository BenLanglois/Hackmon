#ifndef DEBUFF_H
#define DEBUFF_H

#include "debuffName.h"
#include "statName.h"

class Debuff {
  public:
    const DebuffName name;
    const StatName stat;
    const int strength;
    Debuff(const DebuffName name, const StatName stat, const int strength);
};

#endif