#ifndef SPECIES_H_
#define SPECIES_H_

#include <vector>
#include <string>

#include "hackmon.h"
#include "move.h"
#include "stats.h"
#include "family.h"

#include "statName.h"

class Species {
  std::string speciesName;
  std::vector<Move> moves; // FIXME: should be moved to family? depends on type
  Move specialMove;
  Stats stat;
  std::vector<Family> family;
 public:
  Species(const std::string speciesName, std::vector<Move> moves, Move specialMove, map<std::string, Stat> stats, std::vector<Family> family):
    speciesName{speciesName}, moves{moves}, specialMove{specialMove}, family{family} {

      for (auto const& statInfo : StatInfo) stats.insert(make_pair<StatName, Stat>(statInfo.first, Stat(statInfo.second))); //
  }

  Hackmon createHackmon(std::vector<Move>, const std::string hackmonName = std::string()) {
    std::vector<Move> hackmonMoves = moves;
    hackmonMoves.emplaceBack(specialMove);

    return Hackmon(hackmonName.length() ? hackmonName : speciesName, hackmonMoves, family, stats);
  }
};

#endif
