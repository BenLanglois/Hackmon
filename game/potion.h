#ifndef POTION_H
#define POTION_H

#include <string>
#include <vector>

#include "item.h"
#include "statInfo.h"

class Player;

class Potion: public Item {
  const StatName stat;
  const int strength;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override;

public:
  Potion(const std::string, const Scope, const StatName, const int);
};

#endif
