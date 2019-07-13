#ifndef STAT_MOVE_H
#define STAT_MOVE_H

#include <string>
#include <vector>

#include "move.h"
#include "statInfo.h"

class Player;

class StatMove: public Move {
  const StatName stat;
  const int strength;
  virtual void doMoveOverride(Player &player, const std::vector<size_t> &targets) const override;

public:
  StatMove(const std::string name, const Scope scope, const size_t accuracy,
           const Family family, const StatName stat, const int strength);
};

#endif
