#include <vector>
#include <string>
#include <memory>

#include "hackmon.h"
#include "debuffName.h"
#include "statInfo.h"
using namespace std;

Hackmon::Hackmon(string hackmonName, vector<Move> moves, Stats stats, vector<Family> family, Mobility mobility):
name{hackmonName}, moves{moves}, stats{stats}, family{family}, mobility{mobility},
currentMove{nullptr}, debuff{make_unique<Debuff>(HEALTHY, HP, 0)} {}
