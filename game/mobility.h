#ifndef MOBILITY_H_
#define MOBILITY_H_

#include "hackmon.h"

class Mobility {
    Hackmon& h;
    virtual bool canMoveOverride() const = 0;
  public:
    bool canMove() const;
    Mobility(Hackmon &);
};

#endif
