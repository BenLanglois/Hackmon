#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <vector>

#include "actionInfo.h"

class Player;

class Action {
  virtual void doActionOverride(Player &, const std::vector<size_t> &) const = 0;

public:
  void doAction(Player &, const std::vector<size_t> &) const;

  Action();
};

#endif
