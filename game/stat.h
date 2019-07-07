#ifndef STAT_H
#define STAT_H

class Stat {
  public:
    const int base;
    const int min;
    const int max;
    int current;
    Stat(const int base, const int min, const int max, int current);
};

#endif