#ifndef DEBUFF_HEAL_H
#define DEBUFF_HEAL_H

#include <string>
#include <vector>

#include "item.h"
#include "debuff.h"

class Player;

class Potion: public Item {
  DebuffName debuff;
  virtual void doActionOverride(Player &player, const std::vector<size_t> &targets) const override;

public:
  Potion(const std::string name, const Scope scope, DebuffName debuff);
};

#endif
