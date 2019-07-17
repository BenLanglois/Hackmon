#ifndef DEBUFFINFO_H_
#define DEBUFFINFO_H_

#include "statInfo.h"
#include <map>
#include <utility>
#include <string>

enum DebuffName {
  HEALTHY,
  POISONED,
  BURNED,
  FROZEN
};

std::map<DebuffName, StatName> debuffMap = {
  {HEALTHY, HP},
  {POISONED, ATTACK},
  {BURNED, DEFENSE},
  {FROZEN, SPEED}
};

std::map<DebuffName, std::string> debuffString = {
  {HEALTHY, "Healthy"},
  {POISONED, "Posioned"},
  {BURNED, "Burned"},
  {FROZEN, "Frozen"}
};

#endif
