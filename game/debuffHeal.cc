#include <string>
#include <iostream>
#include <iomanip>

#include "debuffHeal.h"
#include "debuff.h"
#include "hackmon.h"
#include "globalConstants.h"

using namespace std;

DebuffHeal::DebuffHeal(const string name, const Scope scope, const DebuffName debuff):
  Item{name, scope}, debuff{debuff} {}

void DebuffHeal::useItemOverride(Hackmon &target) const {
  if (target.debuff.name == debuff) {
    cout << target.name << " is no longer " << debuffString.at(target.debuff.name) << "." << endl;
    target.debuff = Debuff{HEALTHY};
  } else {
    cout << endl;
  }
}

void DebuffHeal::printItem() {
  cout << left << "Item: " << setw(16) << "Debuff Heal";
  cout << "Debuff: " << setw(12) << debuffString.at(debuff);
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==SINGLE ? "Single" : "All");
}

unique_ptr<Item> DebuffHeal::clone() const {
  return make_unique<DebuffHeal>(*this);
}
