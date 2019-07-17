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

extern std::map<DebuffName, StatName> debuffMap;

extern std::map<DebuffName, std::string> debuffString;

#endif
