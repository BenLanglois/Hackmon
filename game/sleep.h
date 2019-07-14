#ifndef SLEEP_H_
#define SLEEP_H_

#include "mobility.h"

class Sleep: public Mobility {
    virtual bool canMoveOverride() override;
  public:
    Sleep(Hackmon &);
};

#endif