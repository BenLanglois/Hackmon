#include <vector>
#include <string>
#include <map>
#include <memory>

#include "hackmon.h"
#include "debuffName.h"
#include "statInfo.h"
using namespace std;

Hackmon::Hackmon(string hackmonName, vector<Move> moves, Stats stats, vector<Family> family):
name{hackmonName}, moves{moves}, stats{stats}, family{family} {
  currentMove = nullptr;
  inBattle = false;
  debuff = make_unique<Debuff>(HEALTHY, HP, 0);
}
