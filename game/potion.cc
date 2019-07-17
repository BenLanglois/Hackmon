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
  cout << target.name << "'s " << statString.at(stat) << "increased from " << target.stats.getStat(stat);
  cout << " to " << target.stats.getStat(stat) + strength << "." << endl;
  target.stats.setStat(stat, target.stats.getStat(stat) + strength);
}

void Potion::printItem() {
  cout << left << "Item: " << setw(16) << name;
  cout << left << "Type: " << setw(16) << "Stat Potion";
  cout << "Stat: " << setw(10) << statString.at(stat);
  cout << "Strength: " << setw(12) << strength;
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==SINGLE ? "Single" : "All");
}

unique_ptr<Item> Potion::clone() const {
  return make_unique<Potion>(*this);
}
