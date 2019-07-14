#ifndef MOBILITY_H_
#define MOBILITY_H_

class Hackmon;

class Mobility {
    Hackmon& h;
    virtual bool canMoveOverride() const = 0;
  public:
    bool canMove() const;
    Mobility(Hackmon &);
};

#endif