#include <vector>
#include <memory>
#include <utility>

#include "player.h"
#include "hackmon.h"
#include "statInfo.h"
using namespace std;

unsigned numberBattling; // REMOVE THIS LATER

// FIXME: numberBattling global variable unsigned int
Player::Player(string name, vector<unique_ptr<Hackmon>> party): name{name}, party{party}, winTotal{0}, nextAlive{numberBattling} {}

bool Player::isAlive(unsigned index) {
  return (party.at(index)->stats.getStat(HP) > 0);
}

// move calls this function -- returns nullptr if no hackmon left
Hackmon* Player::getHackmon(unsigned index) {
  if (isAlive(index)) {
    return party.at(index).get();
  }
  else {
    if (nextAlive < party.size()) {
      swapHackmon(index, nextAlive++);
      return party.at(index).get();
    }
    else {
      return nullptr;
    }
  }
}

// index1 from party, index2 from party not in battle and not fainted
void Player::swapHackmon(unsigned index1, unsigned index2) {
  swap(party.at(index1), party.at(index2));
}

// increment win count
void Player::hasWon() {
  winTotal++;
}
