#ifndef RANDOM_GEN_H_
#define RANDOM_GEN_H_

#include <random>

class RandomGenerator {
    const unsigned min;
    const unsigned max;
    static std::random_device rd;
    static std::mt19937 random_generator;
    std::uniform_int_distribution<unsigned> random_distribution;
  public:
    RandomGenerator(const unsigned, const unsigned);
    unsigned getRandom();
};

#endif
