#ifndef POTION_H
#define POTION_H

#include <string>

#include "item.h"
#include "statInfo.h"

class Potion: public Item {
  const StatName stat;
  const int strength;
  virtual void useItemOverride(Hackmon &) const override;

public:
  Potion(const std::string, const Scope, const StatName, const int);
  virtual void printItem() override;
};

#endif
