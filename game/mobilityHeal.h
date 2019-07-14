#ifndef MOBILITY_HEAL_H
#define MOBILITY_HEAL_H

#include <string>
#include <vector>

#include "item.h"

class Player;
class Mobility;

class MobilityHeal: public Item {
  Mobility &mobility;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override;

public:
  MobilityHeal(const std::string, const Scope, Mobility &);
};

#endif
