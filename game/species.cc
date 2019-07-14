#include <vector>
#include <string>

#include "species.h"
using namespace std;

Species::Species(const string speciesName, Move &specialMove, Stats stats, vector<Family> family):
  speciesName{speciesName}, specialMove{specialMove}, stats{stats}, family{family} {}

Hackmon Species::createHackmon(vector<unique_ptr<Move>> moves, const string hackmonName = string()) {
  vector<unique_ptr<Move>> hackmonMoves = moves;
  hackmonMoves.emplace_back(specialMove);

  return Hackmon(hackmonName.length() ? hackmonName : speciesName, hackmonMoves, stats, family);
}
