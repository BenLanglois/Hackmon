#include "debuff.h"

Debuff::Debuff(const DebuffName name) : name{name}, 
          stat{debuffMap.at(name)}, strength{name == HP ? 0 : defaultStrength} {}

