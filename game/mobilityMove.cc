#include <string>
#include <memory>
#include <iostream>
#include <iomanip>

#include "mobilityMove.h"
#include "family.h"
#include "hackmon.h"
#include "globalConstants.h"
#include "mobilityUtility.h"

using namespace std;

MobilityMove::MobilityMove(const std::string name, const Scope scope, const unsigned accuracy,
                           const Family family, MobilityName mobility):
  Move{name, scope, accuracy, family}, mobility{mobility} {}

void MobilityMove::doMoveOverride(Hackmon &target) const {
  cout << target.name << " is now " << mobilityStringVerb.at(mobility) << "." << endl;
  target.mobility = toMobility(mobility, target);
}

unique_ptr<Move> MobilityMove::clone() const {
  return make_unique<MobilityMove>(*this);
}

void MobilityMove::printMove() {
  cout << left << "Name: " << setw(20) << name;
  cout << "Type: " << setw(12) << typeString.at(family.type);
  cout << "Move Type: " << setw(18) << "Mobility Move";
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==SINGLE ? "Single" : "All");
  cout << "Accuracy: " << accuracy << (accuracy==100 ? setw(10) : setw(11)) << "%";
  cout << "Mobility: " << setw(12) << mobilityString.at(mobility);
}
