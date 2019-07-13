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
  std::vector<unique_ptr<Hackmon>> party;
  int winTotal;
  int nextAlive;

  Player(std::string, std::vector<unique_ptr<Hackmon>>);

  // checks if hp of indicated hackmon is above 0
  bool isAlive(int);

  // move calls this function -- returns nullptr if no hackmon left
  Hackmon* getHackmon(int);

  // index1 from inBattle vector, index2 from party not in inBattle and not fainted
  void swapHackmon(int, int);

  // increment win count
  void hasWon();
};

#endif
