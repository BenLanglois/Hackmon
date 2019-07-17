#include <string>
#include <memory>
#include <iostream>
#include <iomanip>

#include "mobilityHeal.h"
#include "mobile.h"
#include "hackmon.h"
#include "globalConstants.h"

using namespace std;


MobilityHeal::MobilityHeal(const string name, const Scope scope, MobilityName mobility):
  Item{name, scope}, mobility{mobility} {}

void MobilityHeal::useItemOverride(Hackmon &target) const {
  if (target.mobility->name() == mobility) {
    target.mobility = make_unique<Mobile>(target);
  }
}

void MobilityHeal::printItem() {
  cout << left << "Item: " << setw(16) << "Mobility Heal";
  cout << "Mobility: " << setw(12) << mobilityString.at(mobility);
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==SINGLE ? "Single" : "All");
}

unique_ptr<Item> MobilityHeal::clone() const {
  return make_unique<MobilityHeal>(*this);
}
