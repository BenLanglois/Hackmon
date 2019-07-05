#ifndef DEBUFF_MOVE_H
#define DEBUFF_MOVE_H

#include <string>
#include <vector>

#include "move.h"
#include "debuff.h"

class Player;

class DebuffMove: public Move {
  const DebuffName debuff;
  virtual void doActionOverride(Player &player, const std::vector<size_t> &targets) const override;

public:
  DebuffMove(const std::string name, const Scope scope, const size_t accuracy,
             const Family family, const DebuffName debuff);
};

#endif
