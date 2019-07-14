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
  std::vector<std::unique_ptr<Move>> moves; // FIXME: should be moved to family? depends on type
  Move &specialMove;
  Stats stats;
  std::vector<Family> family;
 public:
  Species(const std::string, std::vector<std::unique_ptr<Move>>, Move &, Stats, std::vector<Family>);

  Hackmon createHackmon(std::vector<std::unique_ptr<Move>>, const std::string);
};

#endif
