#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <memory>
#include <utility>

#include "hackmon.h"

class Player {
 public:
  std::string name;
  int winTotal;
  int nextAlive;
  std::vector<unique_ptr<Hackmon>> party;
  std::vector<size_t> inBattle;

  Player(std::string name, std::vector<unique_ptr<Hackmon>> party): name{name}, party{party} {
    winTotal = 0;
    nextAlive = numberBattling; // global variable

    for (auto& index : numberBattling) {
      inBattle.at(index) = party.at(index);
    }
  }

  // move calls this function
  Hackmon& getHackmon() {
    /*
    void hasFainted(int index) {
      if (nextAlive < party.size()) {
        inBattle.at(index) = *party.at(nextAlive);
        nextAlive++;
      } else {
        inBattle.at(index) = nullptr;
      }
    }
    */
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
