#include <string>

#include "potion.h"
#include "hackmon.h"

using namespace std;

Potion::Potion(const string name, const Scope scope, const StatName stat, const int strength):
  Item{name, scope}, stat{stat}, strength{strength} {}

void Potion::useItemOverride(Hackmon &target) const {
  target.stats.setStat(stat, target.stats.getStat(stat) + strength);
}
