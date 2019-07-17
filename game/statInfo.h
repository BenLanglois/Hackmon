#ifndef STATINFO_H_
#define STATINFO_H_

#include <map>
#include <string>

enum StatName {
  HP,
  ATTACK,
  DEFENSE,
  SPEED
};

// Stat to String
extern std::map<StatName, std::string> statString;

#endif
