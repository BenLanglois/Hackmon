#ifndef SPECIES_H_
#define SPECIES_H_

#include <vector>
#include <string>

#include "hackmon.h"

class Species {
  std::string name;
  std::vector<Move> moves;
  Move specialMove;
  map<std::string, Stat> stats; // <StatName, Stat>
  std::vector<Family> family;
 public:
  Hackmon createHackmon(std::string, std::vector<Move>); //  hackmonName, moves
};

#endif
