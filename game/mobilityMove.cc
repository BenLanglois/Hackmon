#include <string>
#include <memory>

#include "mobilityMove.h"
#include "mobility.h"
#include "family.h"
#include "hackmon.h"

using namespace std;

MobilityMove::MobilityMove(const std::string name, const Scope scope, const unsigned accuracy,
                           const Family family, Mobility &mobility):
  Move{name, scope, accuracy, family}, mobility{mobility} {}

void MobilityMove::doMoveOverride(Hackmon &target) const {
  target.mobility = mobility.clone();
}

unique_ptr<Move> MobilityMove::clone() const {
  return make_unique<MobilityMove>(*this);
}
