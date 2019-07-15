#ifndef HACKMON_H_
#define HACKMON_H_

#include <vector>
#include <string>
#include <memory>

#include "move.h"
#include "stats.h"
#include "family.h"
#include "mobility.h"
#include "debuff.h"

class Hackmon {
 public:
  std::string name;
  std::vector<std::unique_ptr<Move>> moves;
  Stats stats;
  std::vector<Family> family;
  std::string speciesName;
  std::unique_ptr<Mobility> mobility;
  std::unique_ptr<Move> currentMove;
  Debuff debuff;

  Hackmon(std::string, std::vector<std::unique_ptr<Move>>, Stats, std::vector<Family>, std::string);
};

#endif
