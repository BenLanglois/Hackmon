#include <string>
#include <vector>
#include <algorithm>

#include "stat_move.h"
#include "statInfo.h"
#include "family.h"
#include "player.h"

using namespace std;

StatMove::StatMove(const std::string name, const Scope scope, const size_t accuracy,
                   const Family family, const StatName stat, const int strength):
  Move{name, scope, accuracy, family}, stat{stat}, strength{strength} {}

void StatMove::doMoveOverride(Hackmon &target) const {
  if (stat == HP) {
    // damage is proportional to strength, effectiveness, and the attacker's Attack stat
    // damage is inversely proportional to the target's Defense stat
    // damage cannot be less than 1

    int attackStat = hackmon.stats.getStat(Attack);
    int defenseStat = hackmon.stats.getStat(Defense);

    if (hackmon.debuff.stat == Attack) {
      attackStat -= hackmon.debuff.strength;
    }
    if (target.debuff.stat == Defense) {
      defenseStat -= hackmon.debuff.strength;
    }

    int damage = max(1, strength
                      * hackmon.family.effectiveness(target.family)
                      * max(1, attackStat)
                      / max(1, defenseStat)
    );

    target.stats.setStat(HP, target.stats.getStat(HP) - damage);

  } else {

  }
}
