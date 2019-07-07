#ifndef STATINFO_H
#define STATINFO_H

#include <vector>

enum StatName {
  HP,
  ATTACK,
  DEFENSE,
  SPEED
};

// name, base, min, max
std::vector<int> hp      = {HP,      80, 0, 100};
std::vector<int> attack  = {ATTACK,  80, 0, 100};
std::vector<int> defense = {DEFENSE, 80, 0, 100};
std::vector<int> speed   = {SPEED,   80, 0, 100};

std::vector<std::vector<int>> = {hp, attack, defense, speed};

#endif
