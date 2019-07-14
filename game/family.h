#ifndef FAMILY_H_
#define FAMILY_H_

#include <vector>
#include "type.h"

class Family {
  public:
    const Type type;
    size_t effectiveness(std::vector<Family>);
    Family(const Type);
};

#endif
