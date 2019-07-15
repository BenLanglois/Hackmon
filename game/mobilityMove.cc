#include <string>
#include <memory>

#include "mobilityMove.h"
#include "family.h"
#include "hackmon.h"

#include "mobilityUtility.h"

using namespace std;

MobilityMove::MobilityMove(const std::string name, const Scope scope, const unsigned accuracy,
                           const Family family, MobilityName mobility):
  Move{name, scope, accuracy, family}, mobility{mobility} {}

void MobilityMove::doMoveOverride(Hackmon &target) const {
  target.mobility = toMobility(mobility, target);
}

unique_ptr<Move> MobilityMove::clone() const {
  return make_unique<MobilityMove>(*this);
}
