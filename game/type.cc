#include <map>
#include <utility>
#include <string>

#include "type.h"

using namespace std;

// Hackmon Type to String
map<Type, string> typeString = {
  {NORMAL, "Normal"},
  {FIRE, "Fire"},
  {WATER, "Water"},
  {ELECTRIC, "Electric"},
  {GRASS, "Grass"},
  {FIGHTING, "Fighting"},
  {GROUND, "Ground"},
  {PSYCHIC, "Psychic"}
};

const map<Type, map<Type,size_t>> typeChart = {
  {NORMAL, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 2}, {WATER, 2}, {ELECTRIC, 2},
            {GRASS, 2}, {FIGHTING, 2}, {GROUND, 2}, {PSYCHIC, 2}}},
  {FIRE, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 1}, {WATER, 1}, {ELECTRIC, 2},
            {GRASS, 4}, {FIGHTING, 2}, {GROUND, 2}, {PSYCHIC, 2}}},
  {WATER, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 4}, {WATER, 1}, {ELECTRIC, 2},
            {GRASS, 1}, {FIGHTING, 2}, {GROUND, 4}, {PSYCHIC, 2}}},
  {ELECTRIC, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 2}, {WATER, 4}, {ELECTRIC, 1},
            {GRASS, 1}, {FIGHTING, 2}, {GROUND, 0}, {PSYCHIC, 2}}},
  {GRASS, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 1}, {WATER, 4}, {ELECTRIC, 2},
            {GRASS, 1}, {FIGHTING, 2}, {GROUND, 4}, {PSYCHIC, 2}}},
  {FIGHTING, std::map<Type,size_t>{{NORMAL, 4}, {FIRE, 2}, {WATER, 2}, {ELECTRIC, 2},
            {GRASS, 2}, {FIGHTING, 2}, {GROUND, 2}, {PSYCHIC, 1}}},
  {GROUND, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 4}, {WATER, 2}, {ELECTRIC, 4},
            {GRASS, 1}, {FIGHTING, 2}, {GROUND, 2}, {PSYCHIC, 2}}},
  {PSYCHIC, std::map<Type,size_t>{{NORMAL, 2}, {FIRE, 2}, {WATER, 2}, {ELECTRIC, 2},
            {GRASS, 2}, {FIGHTING, 4}, {GROUND, 2}, {PSYCHIC, 1}}}
};
