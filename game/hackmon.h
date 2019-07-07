#ifndef HACKMON_H_
#define HACKMON_H_

#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "move.h"
#include "stats.h"
#include "family.h"
#include "mobility.h"

#include "debuffName.h"
#include "statName.h"

class Hackmon {
 public:
  std::string name;
  bool inBattle;
  Move& currentMove;
  Debuff& debuff;
  Mobility mobility;
  map<StatName, Stat> stats;
  std::vector<Move> moves;
  std::vector<Family> family;

  Hackmon(std::string hackmonName, std::vector<Move> moves, std::vector<Family> family):
    name{hackmonName}, moves{moves}, family{family}, stats{stats} {
      currentMove = nullptr;
      inBattle = false;
      debuff
  }
};

#endif
