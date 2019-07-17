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
  Move &specialMove;
  Stats stats;
  std::vector<Family> family;
 public:
  std::string speciesName;
  std::vector<std::string> art;

  Species(const std::string, Move &, Stats, std::vector<Family>);

  std::unique_ptr<Hackmon> createHackmon(std::vector<std::unique_ptr<Move>> &&, const std::string);

  void addArt(std::vector<std::string>);
};

#endif
