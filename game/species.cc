#include <vector>
#include <string>
#include <memory>

#include "species.h"
using namespace std;

Species::Species(const string speciesName, Move &specialMove, Stats stats, vector<Family> family):
  speciesName{speciesName}, specialMove{specialMove}, stats{stats}, family{family} {}

unique_ptr<Hackmon> Species::createHackmon(vector<unique_ptr<Move>> &&moves, const string hackmonName = string()) {
  vector<unique_ptr<Move>> hackmonMoves = move(moves);
  hackmonMoves.emplace_back(specialMove.clone());
  unique_ptr<Hackmon> h = make_unique<Hackmon>(hackmonName.length() ? hackmonName : speciesName, move(hackmonMoves), stats, family, speciesName);
  for(auto& move : h->moves) {
    move->attachHackmon(h.get());
  }
  return h;
}
