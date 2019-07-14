#ifndef DEBUFF_HEAL_H
#define DEBUFF_HEAL_H

#include <string>
#include <vector>

#include "item.h"
#include "debuff.h"

class Player;

class DebuffHeal: public Item {
  const DebuffName debuff;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override;

public:
  DebuffHeal(const std::string, const Scope, const DebuffName);
};

#endif
