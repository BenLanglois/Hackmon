#include <string>
#include <iostream>
#include <iomanip>

#include "debuffMove.h"
#include "debuff.h"
#include "family.h"
#include "hackmon.h"
#include "globalConstants.h"

using namespace std;

DebuffMove::DebuffMove(const std::string name, const Scope scope, const unsigned accuracy,
                       const Family family, const Debuff debuff):
  Move{name, scope, accuracy, family}, debuff{debuff} {}

void DebuffMove::doMoveOverride(Hackmon &target) const {
  cout << target.name << " is now " << debuffString.at(debuff.name) << "." << endl;
  target.debuff = debuff;
}

unique_ptr<Move> DebuffMove::clone() const {
  return make_unique<DebuffMove>(*this);
}

void DebuffMove::printMove() {
  cout << left << "Name: " << setw(20) << name;
  cout << "Type: " << setw(12) << typeString.at(family.type);
  cout << "Move Type: " << setw(18) << "Mobility Move";
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==0 ? "Single" : "All");
  cout << "Accuracy: " << setw(18) << accuracy << "%";
  cout << "Debuff: " << setw(12) << debuffString.at(debuff.name);
}
