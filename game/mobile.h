#ifndef MOBILE_H
#define MOBILE_H

#include "mobility.h"

class Mobile: public Mobility {
    virtual bool canMove() const override;
  public:
    Mobile();
};

#endif