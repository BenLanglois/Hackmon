#include <vector>
#include <utility>

using namespace std;

#include "switch.h"
#include "player.h"

Switch::Switch() {}

void Switch::doActionOverride(Player &player, const vector<size_t> &targets) const {
  swap(player.party.at(targets.at(0)), player.party.at(targets.at(1)));
}
