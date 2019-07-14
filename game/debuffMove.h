#ifndef DEBUFF_MOVE_H
#define DEBUFF_MOVE_H

#include <string>

#include "move.h"
#include "debuff.h"

class DebuffMove: public Move {
  const DebuffName debuff;
  virtual void doMoveOverride(Hackmon &) const override;

public:
  DebuffMove(const std::string, const Scope, const size_t,
             const Family, const DebuffName);
};

#endif
