#include <string>

#include "debuffMove.h"
#include "debuff.h"
#include "family.h"
#include "hackmon.h"

using namespace std;

DebuffMove::DebuffMove(const std::string name, const Scope scope, const unsigned accuracy,
                       const Family family, const Debuff debuff):
  Move{name, scope, accuracy, family}, debuff{debuff} {}

void DebuffMove::doMoveOverride(Hackmon &target) const {
  // target.debuff
}
