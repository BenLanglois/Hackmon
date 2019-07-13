#ifndef DEBUFF_H_
#define DEBUFF_H_

#include "debuffInfo.h"
#include "statInfo.h"

class Debuff {
  public:
    const DebuffName name;
    const StatName stat;
    const int strength;
    Debuff(const DebuffName, const StatName, const int);
};

#endif