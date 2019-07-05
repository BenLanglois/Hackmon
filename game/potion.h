#ifndef POTION_H
#define POTION_H

#include <string>
#include <vector>

#include "item.h"
#include "stat.h"

class Player;

class Potion: public Item {
  StatName stat;
  int strength;
  virtual void doActionOverride(Player &player, const std::vector<size_t> &targets) const override;

public:
  Potion(const std::string name, const Scope scope, StatName stat, int strength);
};

#endif
