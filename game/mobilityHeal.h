#ifndef MOBILITY_HEAL_H
#define MOBILITY_HEAL_H

#include <string>

#include "item.h"
#include "mobilityInfo.h"

class MobilityHeal: public Item {
  MobilityName mobility;
  virtual void useItemOverride(Hackmon &) const override;

public:
  MobilityHeal(const std::string, const Scope, MobilityName);
  virtual void printItem() override;
};

#endif
