#ifndef SLEEP_H_
#define SLEEP_H_

#include "mobility.h"
#include "randomGen.h"

class Sleep: public Mobility {
    virtual bool canMoveOverride() override;
    RandomGenerator rng;
    int duration;
  public:
    Sleep(Hackmon &);
};

#endif