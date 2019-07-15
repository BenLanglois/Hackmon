#include <vector>
#include <memory>
#include <utility>

#include "player.h"
#include "hackmon.h"
#include "statInfo.h"
using namespace std;

// FIXME: remove these 2 later
unsigned numberBattling;
int numberParty;

// FIXME: numberBattling global variable unsigned int
Player::Player(string name, vector<unique_ptr<Hackmon>> &&party, vector<unique_ptr<Item>> &&items):
name{name}, party{move(party)}, items{move(items)}, winTotal{0}, nextAlive{numberBattling} {}

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

// checks if there is a least one hackmon alive in the party
// only need to loop through the numberBattling since they will
// always be swapped to contain alive hackmon (if available)
bool Player::partyAlive() {
  for (unsigned i=0; i<numberBattling; i++) {
    if (!isAlive(i)) return false;
  }
  return true;
}

// increment win count
void Player::hasWon() {
  winTotal++;
}

void Player::printParty() {
  cout << name << "'s HACKMON:" << endl;

  for (int m=0; m<numberParty; m++) {
    cout << m+1 << ". " << party.at(m)->name << endl; // add species name
    if (m == numberParty-1) cout << endl;
  }
}
