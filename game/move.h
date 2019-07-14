#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>
#include <random>

#include "action.h"
#include "family.h"

class Player;
class Hackmon;

class Move: public Action {
  // PRNG
  static std::random_device rd;
  static std::mt19937 random_generator;
  static std::uniform_int_distribution<unsigned int> random_distribution;

protected:
  Hackmon *hackmon; // Non-owning pointer
  const unsigned accuracy; // The percent chance that the move will hit. A value between 1 and 100 inclusive
  const Family family;

  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override final;
  virtual void doMoveOverride(Hackmon &) const = 0;

public:
  void attachHackmon(Hackmon *);

  Move(const std::string, const Scope, const unsigned, const Family);
};

#endif
