#ifndef DEBUFF_HEAL_H
#define DEBUFF_HEAL_H

#include <string>

#include "item.h"
#include "debuffInfo.h"

class DebuffHeal: public Item {
  DebuffName debuff;
  virtual void useItemOverride(Hackmon &target) const override;

public:
  DebuffHeal(const std::string, const Scope, const DebuffName);
  virtual void printItem() override;
};

#endif
