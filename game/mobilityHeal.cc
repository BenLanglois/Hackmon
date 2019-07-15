#include <string>
#include <memory>

#include "mobilityHeal.h"
#include "mobile.h"
#include "hackmon.h"

using namespace std;


MobilityHeal::MobilityHeal(const string name, const Scope scope, MobilityName mobility):
  Item{name, scope}, mobility{mobility} {}

void MobilityHeal::useItemOverride(Hackmon &target) const {
  if (target.mobility->name() == mobility) {
    target.mobility = make_unique<Mobile>(target);
  }
}
