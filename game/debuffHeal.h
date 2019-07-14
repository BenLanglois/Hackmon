#ifndef DEBUFF_HEAL_H
#define DEBUFF_HEAL_H

#include <string>
#include <vector>

#include "item.h"
#include "debuff.h"

class Player;

class DebuffHeal: public Item {
  DebuffName debuff;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override;

public:
  Potion(const std::string, const Scope, DebuffName);
};

#endif
