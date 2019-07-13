#include <vector>
#include <string>

#include "species.h"
using namespace std;

Species::Species(const string speciesName, vector<Move*> moves, Move specialMove, Stats stats, vector<Family> family):
  speciesName{speciesName}, moves{moves}, specialMove{specialMove}, stats{stats}, family{family} {}

Species::Hackmon createHackmon(vector<Move*> moves, const string hackmonName = string()) {
  std::vector<Move> hackmonMoves = moves;
  hackmonMoves.emplaceBack(specialMove);

  return Hackmon(hackmonName.length() ? hackmonName : speciesName, hackmonMoves, family, stats);
}
