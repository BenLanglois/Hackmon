#ifndef MOBILITY_MOVE_H
#define MOBILITY_MOVE_H

#include <string>

#include "move.h"

class Mobility;

class MobilityMove: public Move {
  Mobility &mobility;
  virtual void doMoveOverride(Hackmon &) const override;

public:
  MobilityMove(const std::string, const Scope, size_t, Family, Mobility &);
};

#endif
