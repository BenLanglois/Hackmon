#ifndef SWITCH_H
#define SWITCH_H

#include <vector>

#include "action.h"

class Player;

class Switch: public Action {
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override final;
public:
  Switch();
};

#endif
