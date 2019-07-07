#ifndef MOBILITY_H
#define MOBILITY_H

class Mobility {
    virtual bool canMoveOverride() const = 0;
  public:
    bool canMove() const;
    Mobility();
};

#endif