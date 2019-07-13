#ifndef TYPE_H_
#define TYPE_H_

#include <map>
#include <utility>

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


const std::map<Type, std::map<Type,size_t>> typeChart = {
  {NORMAL, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 100}, {WATER, 100}, {ELECTRIC, 100},
            {GRASS, 100}, {FIGHTING, 100}, {GROUND, 100}, {PSYCHIC, 100}}},
  {FIRE, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 50}, {WATER, 50}, {ELECTRIC, 100},
            {GRASS, 200}, {FIGHTING, 100}, {GROUND, 100}, {PSYCHIC, 100}}},
  {WATER, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 200}, {WATER, 50}, {ELECTRIC, 100},
            {GRASS, 50}, {FIGHTING, 100}, {GROUND, 200}, {PSYCHIC, 100}}},
  {ELECTRIC, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 100}, {WATER, 200}, {ELECTRIC, 50},
            {GRASS, 50}, {FIGHTING, 100}, {GROUND, 0}, {PSYCHIC, 100}}},
  {GRASS, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 50}, {WATER, 200}, {ELECTRIC, 100},
            {GRASS, 50}, {FIGHTING, 100}, {GROUND, 200}, {PSYCHIC, 100}}},
  {FIGHTING, std::map<Type,size_t>{{NORMAL, 200}, {FIRE, 100}, {WATER, 100}, {ELECTRIC, 100},
            {GRASS, 100}, {FIGHTING, 100}, {GROUND, 100}, {PSYCHIC, 50}}},
  {GROUND, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 200}, {WATER, 100}, {ELECTRIC, 200},
            {GRASS, 50}, {FIGHTING, 100}, {GROUND, 100}, {PSYCHIC, 100}}},
  {PSYCHIC, std::map<Type,size_t>{{NORMAL, 100}, {FIRE, 100}, {WATER, 100}, {ELECTRIC, 100},
            {GRASS, 100}, {FIGHTING, 200}, {GROUND, 100}, {PSYCHIC, 50}}}
};

#endif