#include "debuffInfo.h"

#include <map>
#include <utility>
#include <string>

using namespace std;

map<DebuffName, StatName> debuffMap = {
  {HEALTHY, HP},
  {POISONED, ATTACK},
  {BURNED, DEFENSE},
  {FROZEN, SPEED}
};

map<DebuffName, string> debuffString = {
  {HEALTHY, "Healthy"},
  {POISONED, "Posioned"},
  {BURNED, "Burned"},
  {FROZEN, "Frozen"}
};