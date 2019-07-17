#include <string>
#include <vector>
#include <iostream>

#include "move.h"
#include "family.h"
#include "player.h"
#include "hackmon.h"
#include "mobilityInfo.h"

using namespace std;

RandomGenerator Move::rng {1, 100};

Move::Move(const string name, const Scope scope, const unsigned accuracy, const Family family):
  hackmon{nullptr}, accuracy{accuracy}, family{family}, name{name}, scope{scope} {}

void Move::doActionOverride(Player &player, const std::vector<size_t> &targets) const {
  // requires: targets must be distinct and attachHackmon must have already been called

  if (!hackmon->mobility->canMove()) {
    cout << hackmon->name << " cannot move! They are " << mobilityStringVerb.at(hackmon->mobility->name()) << "." << endl;
    return;
  }

  if (rng.getRandom() > accuracy) {
    cout << hackmon->name << " tried to use " << name << ". Oh no! The move missed!" << endl;
    return;
  }

  for (size_t targetIndex: targets) {
    // Call doMoveOverride method for each target
    if (player.isAlive(targetIndex)) {
      Hackmon &target = *player.party.at(targetIndex);
      cout << hackmon->name << " used " << name << " against " << target.name << "." << endl;
      doMoveOverride(target);
      if (!player.isAlive(targetIndex)) {
        cout << target.name << " fainted!" << endl;
        player.hasFainted(targetIndex);
      }
    } else {
      cout << hackmon->name << " tried to use " << name << ". Oh no! The move failed!" << endl;
    }
  }
}

void Move::attachHackmon(Hackmon *new_hackmon) {
  // This should only be called if the Move object isn't already attached to a Hackmon
  hackmon = new_hackmon;
}

Move::~Move() {}
