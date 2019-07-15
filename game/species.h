#ifndef SPECIES_H_
#define SPECIES_H_

#include <vector>
#include <memory>
#include <string>

#include "hackmon.h"
#include "move.h"
#include "stats.h"
#include "family.h"

class Species {
  std::string speciesName;
  Move &specialMove;
  Stats stats;
  std::vector<Family> family;
 public:
  Species(const std::string, Move &, Stats, std::vector<Family>);

  Hackmon createHackmon(std::vector<std::unique_ptr<Move>> &&, const std::string);
};

#endif
