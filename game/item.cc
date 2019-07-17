#include <string>
#include <vector>

#include "item.h"
#include "hackmon.h"
#include "player.h"

using namespace std;

Item::Item(const std::string name, const Scope scope): name{name}, scope{scope} {}

void Item::doActionOverride(Player &player, const std::vector<size_t> &targets) const {
  Hackmon *target = nullptr;
  for (size_t target_index: targets) {
    target = player.getHackmon(target_index);

      cout << player.name << " used " << name << " on " << target->name << "." << endl;
    // the target will never be nullptr since items are used before moves
    useItemOverride(*target);
  }
}

Item::~Item() {}
