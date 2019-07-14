#ifndef STAT_MOVE_H
#define STAT_MOVE_H

#include <string>

#include "move.h"
#include "statInfo.h"

class StatMove: public Move {
  const StatName stat;
  const int strength;
  virtual void doMoveOverride(Hackmon &) const override;

public:
  StatMove(const std::string, const Scope, const unsigned, const Family, const StatName, const int);
};

#endif
