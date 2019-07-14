#include <vector>

#include "type.h"
#include "family.h"

using namespace std;

Family::Family(const Type type): type{type} {}

size_t Family::effectiveness(vector<Family> families) {
  int strength = 1;
  for (auto otherFamily : families) {
    strength *= typeChart.at(type).at(otherFamily.type);
  }
  return strength;
}