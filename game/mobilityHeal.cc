#include <string>

#include "mobilityHeal.h"
#include "mobility.h"
#include "hackmon.h"

using namespace std;


template <typename MobilitySubclass>
MobilityHeal<MobilitySubclass>::MobilityHeal(const string name, const Scope scope, Mobility &mobility):
  Item{name, scope}, mobility{mobility} {}

template <typename MobilitySubclass>
void MobilityHeal<MobilitySubclass>::useItemOverride(Hackmon &target) const {
  /*
  How do we know what type of mobility the Hackmon has?

  Ideas:
  - Each base class has an enum value associated with it. This might be able to remove the need for templates for MobilityMove
  - Mess around with dynamic_cast. See https://stackoverflow.com/questions/11951121/checking-if-a-pointer-points-to-a-particular-class-c
  */
}
