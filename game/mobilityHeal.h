#ifndef MOBILITY_HEAL_H
#define MOBILITY_HEAL_H

#include <string>

#include "item.h"

class Mobility;

template <typename MobilitySubclass>
class MobilityHeal: public Item {
  MobilitySubclass mobility;
  virtual void useItemOverride(Hackmon &) const override;

public:
  MobilityHeal(const std::string, const Scope, Mobility &);
};

#endif
