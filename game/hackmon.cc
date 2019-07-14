#include <vector>
#include <string>
#include <memory>

#include "hackmon.h"
#include "debuffInfo.h"
#include "statInfo.h"
#include "mobile.h"
using namespace std;

Hackmon::Hackmon(string hackmonName, vector<unique_ptr<Move>> moves, Stats stats, vector<Family> family):
  name{hackmonName},
  moves{moves},
  stats{stats},
  family{family},
  mobility{make_unique<Mobile>(*this)},
  currentMove{nullptr},
  debuff{HEALTHY, HP, 0} {}
