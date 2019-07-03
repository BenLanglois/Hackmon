#ifndef HACKMON_H_
#define HACKMON_H_

#include <vector>
#include <string>
#include <map>
#include <tuple>

#include "move.h"
#include "stats.h"
#include "family.h"
#include "mobility.h"

enum StatName {HP, ATTACK, DEFENSE, SPEED};
enum Debuff {HEALTHY, POISONED, BURNED, FROZEN};

class Hackmon {
  std::string name;
  std::vector<Move> moves;
  Move& currentMove;
  map<StatName, Stat> stats; // <StatName, Stat>
  bool inBattle;
  std::vector<Family> family;
  Mobility mobility;
  // FIXME: should change the debuff to be structured similar to Type and Family
  tuple <Debuff, StatName, int> debuff; // <Debuff enum, StatName enum, potency>
 public:
  Hackmon(std::string hackmonName, std::vector<Move> moves, std::vector<Family> family):
    name{hackmonName}, moves{moves}, family{family} {
      currentMove = nullptr;
      inBattle = false;
      stats = for(auto StatName = statName) make_pair<StatName, string>(statName, Stat(statName));
      debuff =
  }
};

#endif
