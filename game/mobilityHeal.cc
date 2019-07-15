#include <string>

#include "mobilityHeal.h"
#include "hackmon.h"
#include "mobility.h"
#include "mobile.h"

using namespace std;


template <typename MobilitySubclass>
MobilityHeal<MobilitySubclass>::MobilityHeal(const string name, const Scope scope, Mobility &mobility):
  Item{name, scope}, mobility{mobility} {}

template <typename MobilitySubclass>
void MobilityHeal<MobilitySubclass>::useItemOverride(Hackmon &target) const {
  if (*(target.mobility) == mobility) {
    target.mobility.reset(new Mobile(target));
  }
}
