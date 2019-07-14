#ifndef MOBILITY_MOVE_H
#define MOBILITY_MOVE_H

#include <string>

#include "move.h"

template <typename MobilitySubclass>
class MobilityMove: public Move {
  MobilitySubclass mobility;
  virtual void doMoveOverride(Hackmon &) const override;

public:
  MobilityMove(const std::string, const Scope, unsigned, Family, MobilitySubclass);
};

#endif
