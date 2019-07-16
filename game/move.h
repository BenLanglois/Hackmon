#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>
#include <memory>

#include "action.h"
#include "family.h"
#include "randomGen.h"

class Player;
class Hackmon;

class Move: public Action {
  static RandomGenerator rng;

protected:
  Hackmon *hackmon; // Non-owning pointer
  const unsigned accuracy; // The percent chance that the move will hit. A value between 1 and 100 inclusive
  const Family family;

  virtual void doActionOverride(Player &, const std::vector<size_t> &) const override final;
  virtual void doMoveOverride(Hackmon &) const = 0;

public:
  void attachHackmon(Hackmon *);
  virtual std::unique_ptr<Move> clone() const = 0;

  Move(const std::string, const Scope, const unsigned, const Family);

  virtual void printMove() = 0;

  virtual ~Move() = 0;
};

#endif
