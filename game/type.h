#ifndef TYPE_H_
#define TYPE_H_

#include <map>
#include <utility>
#include <string>

enum Type {
  NORMAL,
  FIRE,
  WATER,
  ELECTRIC,
  GRASS,
  FIGHTING,
  GROUND,
  PSYCHIC,
};

// Hackmon Type to String
extern std::map<Type, std::string> typeString;

extern const std::map<Type, std::map<Type,size_t>> typeChart;

#endif
