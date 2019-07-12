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
  int winTotal;
  int nextAlive;
  std::vector<unique_ptr<Hackmon>> party;

  Player(std::string name, std::vector<unique_ptr<Hackmon>> party): name{name}, party{party} {
    winTotal = 0;
    nextAlive = numberBattling; // global variable

    for (auto& index : numberBattling) {
      inBattle.at(index) = party.at(index);
    }
  }

  bool isAlive(int index) {
    return (*(party.at(index)).stats.getStat(HP) > 0);
  }

  // move calls this function -- returns nullptr if no hackmon left
  Hackmon* getHackmon(int index) {
    if (isAlive(*(inBattle.at(index)))) {
      return party.at(*(inBattle.at(index)));
    }
    else {
      if (nextAlive < party.size()) {
        inBattle.at(index) = *party.at(nextAlive++);
        return party.at(*(inBattle.at(index)));
      }
      else {
        inBattle.at(index) = nullptr;
        return nullptr;
      }
    }
  }

  // index1 from inBattle vector, index2 from party not in inBattle and not fainted
  void swapHackmon(int index1, int index2) {
    swap(inBattle.at(index1), party.at(index2));
  }

  // increment win count
  void hasWon() {
    winTotal++;
  }
};

#endif
