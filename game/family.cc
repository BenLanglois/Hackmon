#include <string>

#include "type.h"
#include "family.h"

using namespace std;

Family::Family(const Type type): type{type} {}

size_t Family::effectiveness(Family otherFamily) {
  return typeChart.at(type).at(otherFamily.type);
}
