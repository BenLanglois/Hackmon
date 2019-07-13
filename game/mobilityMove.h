#ifndef MOBILITY_MOVE_H
#define MOBILITY_MOVE_H

#include <memory>
#include <string>
#include <vector>

#include "move.h"
#include "mobility.h"

class Player;

class MobilityMove: public Move {
  Mobility &mobility;
  virtual void doMoveOverride(Hackmon &target) const override;

public:
  MobilityMove(const std::string name, const Scope scope, size_t accuracy, Family family, Mobility &mobility);
};

#endif
