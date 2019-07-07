#ifndef SLEEP_H
#define SLEEP_H

#include "mobility.h"

class Sleep: public Mobility {
    virtual bool canMoveOverride() const override;
  public:
    Sleep();
};

#endif