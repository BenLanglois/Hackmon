#include <vector>
#include <utility>

#include "switch.h"
#include "player.h"

using namespace std;

Switch::Switch() {}

void Switch::doActionOverride(Player &player, const vector<size_t> &targets) const {
  player.swapHackmon(targets.at(0), targets.at(1));
}
