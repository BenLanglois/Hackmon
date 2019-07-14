#ifndef MOBILE_H_
#define MOBILE_H_

#include "mobility.h"

class Mobile: public Mobility {
    virtual bool canMoveOverride() const override;
  public:
    Mobile(Hackmon &);
};

#endif
