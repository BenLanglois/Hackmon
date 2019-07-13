#ifndef MOBILITY_H_
#define MOBILITY_H_

class Mobility {
    virtual bool canMoveOverride() const = 0;
  public:
    bool canMove() const;
    Mobility();
};

#endif