#include <string>
#include <vector>

#include "move.h"
#include "family.h"
#include "player.h"
#include "hackmon.h"

using namespace std;

// Initialize PRNG
random_device Move::rd {};
mt19937 Move::random_generator {rd()};
uniform_int_distribution<unsigned int> Move::random_distribution {1, 100};

Move::Move(const string name, const Scope scope, const unsigned accuracy, const Family family):
  Action{name, scope}, hackmon{nullptr}, accuracy{accuracy}, family{family} {}

void Move::doActionOverride(Player &player, const std::vector<size_t> &targets) const {
  // requires: targets must be distinct and attachHackmon must have already been called

  if (!hackmon->mobility->canMove()) {
    // FIXME: Print "can't move" or something
    // or, should that be the responsibility of mobility?
    return;
  }

  if (random_distribution(random_generator) > accuracy) {
    // FIXME: Print "move missed" or something
    return;
  }

  Hackmon *target = nullptr;
  for (size_t target_index: targets) {
    // Call doMoveOverride method for each target
    target = player.getHackmon(target_index);
    if (target != nullptr) {
      doMoveOverride(*target);
    } else {
      // FIXME: Print "move failed" or something
    }
  }
}

void Move::attachHackmon(Hackmon *new_hackmon) {
  // This should only be called if the Move object isn't already attached to a Hackmon
  hackmon = new_hackmon;
}
