#ifndef FAMILY_H_
#define FAMILY_H_

#include "type.h"

class Family {
  public:
    const Type type;
    size_t effectiveness(Family);
    Family(const Type);
};

#endif