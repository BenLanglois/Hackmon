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
  Move& currentMove;
  std::unique_ptr<Debuff> debuff;
  Mobility mobility;
  Stats stats;
  std::vector<Move> moves;
  std::vector<Family> family;

  Hackmon(std::string, std::vector<Move>, Stats, std::vector<Family>);
};

#endif
