#ifndef MOBILITY_MOVE_H
#define MOBILITY_MOVE_H

#include <string>

#include "move.h"
#include "mobilityInfo.h"
class Mobility;

class MobilityMove: public Move {
  MobilityName mobility;
  virtual void doMoveOverride(Hackmon &) const override;

public:
  MobilityMove(const std::string, const Scope, unsigned, Family, MobilityName);
  virtual std::unique_ptr<Move> clone() const override;
  virtual void printMove() override;
};

#endif
