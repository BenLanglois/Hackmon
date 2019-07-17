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
  virtual std::unique_ptr<Item> clone() const override;
};

#endif
