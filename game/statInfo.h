#ifndef STATINFO_H
#define STATINFO_H

#include <vector>
#include <map>

enum StatName {
  HP,
  ATTACK,
  DEFENSE,
  SPEED
};

// base, min, max
std::vector<int> hp      = {80, 0, 100};
std::vector<int> attack  = {80, 0, 100};
std::vector<int> defense = {80, 0, 100};
std::vector<int> speed   = {80, 0, 100};

std::map<StatName, std::vector<int>> StatInfo = {
  {HP, hp},
  {ATTACK, attack},
  {DEFENSE, defense},
  {SPEED, speed},
};

#endif
