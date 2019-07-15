#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <memory>
#include <utility>

#include "hackmon.h"
#include "statInfo.h"

class Player {
 public:
  std::string name;
  std::vector<std::shared_ptr<Hackmon>> party;
  unsigned winTotal;
  unsigned nextAlive;

  Player(std::string, std::vector<std::shared_ptr<Hackmon>>);

  // checks if hp of indicated hackmon is above 0
  bool isAlive(unsigned);

  // move calls this function -- returns nullptr if no hackmon left
  Hackmon* getHackmon(unsigned);

  // index1 from inBattle vector, index2 from party not in inBattle and not fainted
  void swapHackmon(unsigned, unsigned);

  // increment win count
  void hasWon();
};

#endif
