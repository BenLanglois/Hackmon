#include <string>

#include "debuffHeal.h"
#include "debuff.h"
#include "hackmon.h"


using namespace std;

DebuffHeal::DebuffHeal(const string name, const Scope scope, const DebuffName debuff):
  Item{name, scope}, debuff{debuff} {}

void DebuffHeal::useItemOverride(Hackmon &target) const {
  if (target.debuff.name == debuff) {
    target.debuff = Debuff{HEALTHY};
  }
}

unique_ptr<Item> DebuffHeal::clone() const {
  return make_unique<DebuffHeal>(*this);
}
