#include <string>
#include <vector>

#include "action.h"
class Player;

using namespace std;

Action::Action(const string name, const Scope scope): name{name}, scope{scope} {}

void doAction(Player &player, const vector<size_t> &targets) const {
  doActionOverride(player, targets);
}
