#ifndef DEBUFF_MOVE_H
#define DEBUFF_MOVE_H

#include <string>

#include "move.h"
#include "debuff.h"

class DebuffMove: public Move {
  const Debuff debuff;
  virtual void doMoveOverride(Hackmon &) const override;

public:
  DebuffMove(const std::string, const Scope, const unsigned,
             const Family, const Debuff);
  virtual std::unique_ptr<Move> clone() const override;
};

#endif
