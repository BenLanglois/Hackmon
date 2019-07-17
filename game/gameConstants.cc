#include <vector>
#include <string>
#include <memory>

#include "gameConstants.h"

using namespace std;

void fillSpecialMoveList(vector<unique_ptr<Move>> & specialMoveList) {
  specialMoveList.emplace_back(make_unique<StatMove>("Tail Whip", SINGLE, 100, Family(NORMAL), DEFENSE, 5));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Yawn", SINGLE, 100, Family(NORMAL), SLEEP));
  specialMoveList.emplace_back(make_unique<StatMove>("Fire Spin", SINGLE, 100, Family(FIRE), HP, 5));
  specialMoveList.emplace_back(make_unique<DebuffMove>("Heat Wave", ALL, 50, Family(FIRE), Debuff(BURNED)));
  specialMoveList.emplace_back(make_unique<StatMove>("Surf", ALL, 100, Family(WATER), HP, 5));
  specialMoveList.emplace_back(make_unique<StatMove>("Water Gun", SINGLE, 90, Family(WATER), HP, 5));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Thunder Shock", SINGLE, 80, Family(ELECTRIC), PARALYSIS));
  specialMoveList.emplace_back(make_unique<StatMove>("Self-Destruct", ALL, 100, Family(ELECTRIC), HP, 5));
  specialMoveList.emplace_back(make_unique<StatMove>("Vine Whip", SINGLE, 70, Family(GRASS), HP, 4));
  specialMoveList.emplace_back(make_unique<DebuffMove>("Poison Thorn", SINGLE, 100, Family(GRASS), Debuff(POISONED)));
  specialMoveList.emplace_back(make_unique<StatMove>("Seismic Toss", SINGLE, 60, Family(FIGHTING), HP, 5));
  specialMoveList.emplace_back(make_unique<StatMove>("Low Kick", SINGLE, 80, Family(FIGHTING), HP, 4));
  specialMoveList.emplace_back(make_unique<StatMove>("Rock Slide", ALL, 100, Family(GROUND), ATTACK, 3));
  specialMoveList.emplace_back(make_unique<StatMove>("Sand Attack", ALL, 100, Family(GROUND), DEFENSE, 1));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Psybeam", SINGLE, 100, Family(PSYCHIC), CONFUSION));
  specialMoveList.emplace_back(make_unique<MobilityMove>("Hypnosis", SINGLE, 100, Family(PSYCHIC), SLEEP));
}

void fillMoveList(vector<unique_ptr<Move>> & moveList) {
    // normal
  moveList.emplace_back(make_unique<StatMove>("Growl", SINGLE, 100, Family(NORMAL), ATTACK, 2));
  moveList.emplace_back(make_unique<StatMove>("Quick Attack", SINGLE, 100, Family(NORMAL), HP, 4));
  moveList.emplace_back(make_unique<StatMove>("Swift", SINGLE, 100, Family(NORMAL), SPEED, 3));
  moveList.emplace_back(make_unique<StatMove>("Defense Curl", SINGLE, 60, Family(NORMAL), DEFENSE, 2));
  moveList.emplace_back(make_unique<MobilityMove>("Smokescreen", SINGLE, 100, Family(NORMAL), CONFUSION));
  // fire
  moveList.emplace_back(make_unique<StatMove>("Flamethrower", SINGLE, 100, Family(FIRE), HP, 2));
  moveList.emplace_back(make_unique<StatMove>("Fire Blast", ALL, 80, Family(FIRE), HP, 3));
  moveList.emplace_back(make_unique<StatMove>("Overheat", SINGLE, 100, Family(FIRE), ATTACK, 1));
  moveList.emplace_back(make_unique<MobilityMove>("Heat Wave", ALL, 50, Family(FIRE), CONFUSION));
  moveList.emplace_back(make_unique<DebuffMove>("Ember", SINGLE, 100, Family(FIRE), Debuff(BURNED)));
  // water
  moveList.emplace_back(make_unique<StatMove>("Waterfall", ALL, 50, Family(WATER), HP, 5));
  moveList.emplace_back(make_unique<StatMove>("Bubble Beam", SINGLE, 100, Family(WATER), DEFENSE, 1));
  moveList.emplace_back(make_unique<StatMove>("Aqua Jet", SINGLE, 80, Family(WATER), SPEED, 3));
  moveList.emplace_back(make_unique<MobilityMove>("Splishy Splash", SINGLE, 50, Family(WATER), PARALYSIS));
  moveList.emplace_back(make_unique<DebuffMove>("Icy Wind", SINGLE, 100, Family(WATER), Debuff(FROZEN)));
  // electric
  moveList.emplace_back(make_unique<StatMove>("Shock Wave", ALL, 60, Family(ELECTRIC), DEFENSE, 5));
  moveList.emplace_back(make_unique<StatMove>("Zap Cannon", SINGLE, 80, Family(ELECTRIC), HP, 4));
  moveList.emplace_back(make_unique<StatMove>("Charge", SINGLE, 100, Family(ELECTRIC), ATTACK, 2));
  moveList.emplace_back(make_unique<StatMove>("Thunder Wave", ALL, 70, Family(ELECTRIC), HP, 3));
  moveList.emplace_back(make_unique<MobilityMove>("Discharge", SINGLE, 100, Family(ELECTRIC), PARALYSIS));
  // grass
  moveList.emplace_back(make_unique<StatMove>("Leaf Storm", ALL, 80, Family(GRASS), HP, 2));
  moveList.emplace_back(make_unique<StatMove>("Magical Leaf", SINGLE, 60, Family(GRASS), DEFENSE, 5));
  moveList.emplace_back(make_unique<StatMove>("Charge", SINGLE, 100, Family(GRASS), ATTACK, 2));
  moveList.emplace_back(make_unique<DebuffMove>("Stink Bomb", ALL, 40, Family(GRASS), Debuff(POISONED)));
  moveList.emplace_back(make_unique<MobilityMove>("Sleep Powder", SINGLE, 100, Family(GRASS), SLEEP));
  // fighting
  moveList.emplace_back(make_unique<StatMove>("Hammer Arm", SINGLE, 90, Family(FIGHTING), SPEED, 2));
  moveList.emplace_back(make_unique<StatMove>("Double Kick", ALL, 80, Family(FIGHTING), HP, 3));
  moveList.emplace_back(make_unique<StatMove>("Rock Smash", SINGLE, 70, Family(FIGHTING), DEFENSE, 3));
  moveList.emplace_back(make_unique<StatMove>("Close Combat", SINGLE, 100, Family(FIGHTING), ATTACK, 4));
  moveList.emplace_back(make_unique<MobilityMove>("Force Palm", SINGLE, 100, Family(FIGHTING), PARALYSIS));
  // ground
  moveList.emplace_back(make_unique<StatMove>("Sand Attack", SINGLE, 100, Family(GROUND), DEFENSE, 1));
  moveList.emplace_back(make_unique<StatMove>("Earthquake", ALL, 60, Family(GROUND), HP, 3));
  moveList.emplace_back(make_unique<StatMove>("Stealth Rock", SINGLE, 70, Family(GROUND), ATTACK, 3));
  moveList.emplace_back(make_unique<DebuffMove>("Quicksand", SINGLE, 80, Family(GROUND), Debuff(FROZEN)));
  moveList.emplace_back(make_unique<MobilityMove>("Smack Down", SINGLE, 50, Family(GROUND), CONFUSION));
  // psychic
  moveList.emplace_back(make_unique<StatMove>("Trick", SINGLE, 80, Family(PSYCHIC), ATTACK, 1));
  moveList.emplace_back(make_unique<StatMove>("Barrier Break", ALL, 60, Family(PSYCHIC), DEFENSE, 3));
  moveList.emplace_back(make_unique<StatMove>("Psywave", ALL, 100, Family(PSYCHIC), HP, 2));
  moveList.emplace_back(make_unique<MobilityMove>("Telekinesis", SINGLE, 50, Family(PSYCHIC), PARALYSIS));
  moveList.emplace_back(make_unique<MobilityMove>("Confusion", ALL, 40, Family(PSYCHIC), CONFUSION));
}

void fillItemList(vector<unique_ptr<Item>> & itemList) {
  // hp potion
  itemList.emplace_back(make_unique<Potion>("Potion", SINGLE, HP, 50));
  itemList.emplace_back(make_unique<Potion>("Super Potion", SINGLE, HP, 100));
  itemList.emplace_back(make_unique<Potion>("Multi-Potion", ALL, HP, 30));
  // mobility heals
  itemList.emplace_back(make_unique<MobilityHeal>("Awakening", SINGLE, SLEEP));
  itemList.emplace_back(make_unique<MobilityHeal>("Paralyze Heal", SINGLE, PARALYSIS));
  // debuff heals
  itemList.emplace_back(make_unique<DebuffHeal>("Antidote", SINGLE, POISONED));
  itemList.emplace_back(make_unique<DebuffHeal>("Burn Heal", SINGLE, BURNED));
  itemList.emplace_back(make_unique<DebuffHeal>("Ice Heal", SINGLE, FROZEN));
}