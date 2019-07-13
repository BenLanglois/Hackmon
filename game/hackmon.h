#ifndef HACKMON_H_
#define HACKMON_H_

#include <vector>
#include <string>
#include <memory>

#include "move.h"
#include "stats.h"
#include "family.h"
#include "mobility.h"

class Hackmon {
 public:
  std::string name;
  std::vector<Move*> moves;
  Stats stats;
  std::vector<Family> family;
  std::unique_ptr<Mobility> mobility;
  std::unique_ptr<Move> currentMove;
  std::unique_ptr<Debuff> debuff;

  Hackmon(std::string, std::vector<Move*>, Stats, std::vector<Family>, std::unique_ptr<Mobility>);
};

#endif
