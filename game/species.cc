#include <vector>
#include <string>

#include "species.h"
using namespace std;

Species::Species(const string speciesName, vector<shared_ptr<Move>> moves, Move &specialMove, Stats stats, vector<Family> family):
  speciesName{speciesName}, moves{moves}, specialMove{specialMove}, stats{stats}, family{family} {}

Hackmon Species::createHackmon(vector<shared_ptr<Move>> moves, const string hackmonName = string()) {
  vector<shared_ptr<Move>> hackmonMoves = moves;
  hackmonMoves.emplace_back(specialMove);

  return Hackmon(hackmonName.length() ? hackmonName : speciesName, hackmonMoves, stats, family);
}
