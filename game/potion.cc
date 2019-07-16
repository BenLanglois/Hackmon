#include <string>
#include <iostream>
#include <iomanip>

#include "potion.h"
#include "hackmon.h"
#include "globalConstants.h"

using namespace std;

Potion::Potion(const string name, const Scope scope, const StatName stat, const int strength):
  Item{name, scope}, stat{stat}, strength{strength} {}

void Potion::useItemOverride(Hackmon &target) const {
  target.stats.setStat(stat, target.stats.getStat(stat) + strength);
}

void Potion::printItem() {
  cout << left << "Item: " << setw(16) << "Stat Potion";
  cout << "Stat: " << setw(10) << statString[stat];
  cout << "Strength: " << setw(12) << strength;
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==0 ? "Single" : "All");
}
