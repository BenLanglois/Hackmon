#ifndef FAMILY_H_
#define FAMILY_H_

#include <vector>
#include "type.h"

class Family {
  public:
    const Type type;
    size_t effectiveness(const std::vector<Family>) const;
    Family(const Type);
};

#endif
