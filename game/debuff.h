#ifndef DEBUFF_H_
#define DEBUFF_H_

#include "debuffInfo.h"
#include "statInfo.h"

class Debuff {
    static const int defaultStrength = 3;
  public:
    DebuffName name;
    StatName stat;
    int strength;
    Debuff(const DebuffName);
};

#endif
