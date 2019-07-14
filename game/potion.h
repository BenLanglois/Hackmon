#ifndef POTION_H
#define POTION_H

#include <string>
#include <vector>

#include "item.h"
#include "statInfo.h"

class Player;

class Potion: public Item {
  StatName stat;
  int strength;
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override;

public:
  Potion(const std::string, const Scope, StatName, int);
};

#endif
