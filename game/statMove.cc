#include <string>
#include <iostream>
#include <iomanip>

#include "statMove.h"
#include "statInfo.h"
#include "family.h"
#include "hackmon.h"
#include "type.h"
#include "globalConstants.h"
#include "actionInfo.h"
using namespace std;

StatMove::StatMove(const std::string name, const Scope scope, const unsigned accuracy,
                   const Family family, const StatName stat, const int strength):
  Move{name, scope, accuracy, family}, stat{stat}, strength{strength} {}

void StatMove::doMoveOverride(Hackmon &target) const {
  if (stat == HP) {
    // damage is proportional to strength, effectiveness, and the attacker's ATTACK stat
    // damage is inversely proportional to the target's Defense stat
    // damage cannot be less than 1

    int attackerAttackStat = hackmon->stats.getStat(ATTACK);
    int targetDefenseStat = target.stats.getStat(DEFENSE);

    if (hackmon->debuff.stat == ATTACK) {
      attackerAttackStat -= hackmon->debuff.strength;
    }
    if (target.debuff.stat == DEFENSE) {
      targetDefenseStat -= target.debuff.strength;
    }

    int damage = max(1, strength
                      * (int) family.effectiveness(target.family)
                      * max(1, attackerAttackStat)
                      / max(1, targetDefenseStat)
    );

    target.stats.setStat(HP, target.stats.getStat(HP) - damage);

  } else {
    // We don't care about effectiveness, ATTACK, or DEFENSE for non-damage stat moves
    target.stats.setStat(stat, target.stats.getStat(stat) - strength);
  }
}

unique_ptr<Move> StatMove::clone() const {
  return make_unique<StatMove>(*this);
}

void StatMove::printMove() {
  cout << left << "Name: " << setw(20) << name;
  cout << "Type: " << setw(12) << typeString.at(family.type);
  cout << "Move Type: " << setw(18) << "Stat Move";
  if (numberBattling > 1) cout << "Scope: " << setw(18) << (scope==0 ? "Single" : "All");
  cout << "Accuracy: " << setw(18) << accuracy << "%";
  cout << "Stat: " << setw(10) << statString.at(stat);
  cout << "Strength: " << setw(12) << strength;
}
