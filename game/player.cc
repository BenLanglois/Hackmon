#include <vector>
#include <memory>
#include <utility>

#include "player.h"
#include "hackmon.h"
#include "statInfo.h"
using namespace std;

Player::Player(string name, vector<unique_ptr<Hackmon>> party): name{name}, party{party}, winTotal{0} {
  nextAlive = numberBattling; // FIXME: global variable

  for (auto& index : numberBattling) {
    inBattle.at(index) = party.at(index);
  }
}

Player::bool isAlive(int index) {
  return (*(party.at(index)).stats.getStat(HP) > 0);
}

// move calls this function -- returns nullptr if no hackmon left
Player::Hackmon* getHackmon(int index) {
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
Player::void swapHackmon(int index1, int index2) {
  swap(inBattle.at(index1), party.at(index2));
}

// increment win count
Player::void hasWon() {
  winTotal++;
}
