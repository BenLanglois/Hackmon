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
  std::string name;
  bool inBattle;
  Move& currentMove;x
  Debuff& debuff;
  Mobility mobility;
  map<StatName, Stat> stats;
  std::vector<Move> moves;
  std::vector<Family> family;
 public:
  Hackmon(std::string hackmonName, std::vector<Move> moves, std::vector<Family> family): name{hackmonName}, moves{moves}, family{family} {
    currentMove = nullptr;
    inBattle = false;

    for(const auto statName : StatName::All ) stats.insert(make_pair<StatName, string>(statName, Stat(statName)));
  }
};

#endif
