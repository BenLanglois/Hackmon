#ifndef CONFUSION_H
#define CONFUSION_H

#include "mobility.h"

class Confusion: public Mobility {
    virtual bool canMoveOverride() const override;
  public:
    Confusion(Hackmon &);
};

#endif