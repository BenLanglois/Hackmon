#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include "hackmon.h"

class Player {
  std::string name;
  int winTotal;
  std::vector<Hackmon> party;
};

#endif
