#include <vector>
#include <string>
#include <memory>

#include "hackmon.h"
#include "debuffInfo.h"
#include "statInfo.h"
#include "mobile.h"
using namespace std;

Hackmon::Hackmon(string hackmonName, vector<unique_ptr<Move>> moves, Stats stats, vector<Family> family, string speciesName):
  name{hackmonName},
  moves{moves},
  stats{stats},
  family{family},
  speciesName{speciesName},
  mobility{make_unique<Mobile>(*this)},
  currentMove{nullptr},
  debuff{HEALTHY, HP, 0} {}
