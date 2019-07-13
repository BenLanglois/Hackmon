#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <random>

#include "action.h"
#include "family.h"


class Move: public Action {
  // PRNG
  static std::random_device rd;
  static std::mt19937 random_generator;
  static std::uniform_int_distribution<unsigned int> random_distribution;

protected:
  Hackmon *hackmon; // Non-owning pointer
  const unsigned int accuracy; // The percent chance that the move will hit. A value between 1 and 100 inclusive
  const Family family;

  virtual void doActionOverride(Player &player, const std::vector<size_t> &targets) const override final;
  virtual void doMoveOverride(Hackmon &target) const = 0;

public:
  void attachHackmon(Hackmon *hackmon);

  Move(const std::string name, const Scope scope, const size_t accuracy, const Family family);
};

#endif
