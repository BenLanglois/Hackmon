#include <string>
#include <vector>

#include "action.h"
class Player;

using namespace std;

Action::Action() {}

void Action::doAction(Player &player, const vector<size_t> &targets) const {
  doActionOverride(player, targets);
}
