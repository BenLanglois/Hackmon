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
  virtual void doMoveOverride(Hackmon &target) const override;

public:
  StatMove(const std::string name, const Scope scope, const unsigned accuracy,
           const Family family, const StatName stat, const int strength);
};

#endif
