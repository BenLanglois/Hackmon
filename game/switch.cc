#include <vector>
#include <utility>

#include "switch.h"
#include "player.h"

using namespace std;

Switch::Switch() {}

void Switch::doActionOverride(Player &player, const vector<size_t> &targets) const {
  cout << player.party.at(targets.at(0))->name << " has been swapped out with " << player.party.at(targets.at(1))->name << "." << endl;
  player.swapHackmon(targets.at(0), targets.at(1));
}
