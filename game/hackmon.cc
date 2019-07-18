#include <vector>
#include <string>
#include <memory>

#include "hackmon.h"
#include "debuffInfo.h"
#include "statInfo.h"
#include "mobile.h"
using namespace std;

Hackmon::Hackmon(string hackmonName, vector<unique_ptr<Move>> &&moves, Stats stats, vector<Family> family, string speciesName, vector<string> art):
  name{hackmonName},
  moves{move(moves)}, // This line makes sense. I promise.
  stats{stats},
  family{family},
  art{art},
  speciesName{speciesName},
  mobility{make_unique<Mobile>(*this)},
  currentMove{nullptr},
  debuff{HEALTHY} {}

void Hackmon::restore() {
  stats.restoreBaseStats();
  mobility.reset(new Mobile(*this));
  debuff = HEALTHY;
}
