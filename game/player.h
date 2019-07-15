#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <memory>
#include <utility>
#include <iostream>

#include "hackmon.h"
#include "statInfo.h"

class Player {
 public:
  std::string name;
  std::vector<std::unique_ptr<Hackmon>> party;
  unsigned winTotal;
  unsigned nextAlive;
  std::vector<Item> items;

  Player(std::string, std::vector<std::unique_ptr<Hackmon>>, std::vector<Item> items;);

  // checks if hp of indicated hackmon is above 0
  bool isAlive(unsigned);

  // move calls this function -- returns nullptr if no hackmon left
  Hackmon* getHackmon(unsigned);

  // index1 from inBattle vector, index2 from party not in inBattle and not fainted
  void swapHackmon(unsigned, unsigned);

  // checks if there is a least one pokemon alive in the party
  bool partyAlive();

  // increment win count
  void hasWon();

  // print out list of HACKMON
  void printParty();
};

#endif
