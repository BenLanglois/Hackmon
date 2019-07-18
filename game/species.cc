#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <iomanip>

#include "species.h"
#include "statInfo.h"
using namespace std;

Species::Species(const string speciesName, Move &specialMove, Stats stats, vector<Family> family):
  specialMove{specialMove}, stats{stats}, family{family}, speciesName{speciesName} {}

unique_ptr<Hackmon> Species::createHackmon(vector<unique_ptr<Move>> &&moves, const string hackmonName = string()) {
  vector<unique_ptr<Move>> hackmonMoves = move(moves);
  hackmonMoves.emplace_back(specialMove.clone());
  unique_ptr<Hackmon> h = make_unique<Hackmon>(hackmonName.length() ? hackmonName : speciesName, move(hackmonMoves), stats, family, speciesName, art);
  for(auto& move : h->moves) {
    move->attachHackmon(h.get());
  }
  return h;
}

void Species::addArt(vector<string> artVector) {
  art = artVector;
}

void Species::printSpecies() {
  cout << left << setw(19) << speciesName;
  cout << " HP: " << setw(10) << stats.getStat(HP);
  cout << " Attack: " << setw(10) << stats.getStat(ATTACK);
  cout << " Defense: " << setw(10) << stats.getStat(DEFENSE);
  cout << " Speed: " << setw(10) << stats.getStat(SPEED);
  cout << " Type: " << setw(20);
  if (family.size() == 1) {
    cout << typeString.at(family.at(0).type);
  } else {
    string types = "";
    for (size_t i=0; i<family.size(); ++i) {
      if (i!=0) types += ", ";
      types += typeString.at(family.at(i).type);
    }
  }
}
