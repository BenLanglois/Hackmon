#include <string>
#include <memory>

#include "mobilityMove.h"
#include "mobility.h"
#include "family.h"
#include "hackmon.h"

using namespace std;

template <typename MobilitySubclass>
MobilityMove<MobilitySubclass>::MobilityMove(const std::string name, const Scope scope, const unsigned accuracy,
                           const Family family, MobilitySubclass mobility):
  Move{name, scope, accuracy, family}, mobility{mobility} {}

template <typename MobilitySubclass>
void MobilityMove<MobilitySubclass>::doMoveOverride(Hackmon &target) const {
  target.mobility.reset(new MobilitySubclass{mobility});
}
