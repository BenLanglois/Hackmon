#ifndef FAMILY_H_
#define FAMILY_H_

#include <string>
#include "type.h"

class Family {
  public:
    const Type type;
    std::size_t effectiveness(Family otherFamily);
    Family(const Type type);
};

#endif