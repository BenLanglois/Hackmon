#ifndef MOBILITY_HEAL_H
#define MOBILITY_HEAL_H

#include <string>
#include <vector>

#include "item.h"
#include "mobility.h"

class Player;

class MobilityHeal: public Item {
  Mobility mobility;
  virtual void doActionOverride(Player &player, const std::vector<size_t> &targets) const override;

public:
  Potion(const std::string name, const Scope scope, Mobility mobility);
};

#endif
