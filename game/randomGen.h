#ifndef RANDOM_GEN_H_
#define RANDOM_GEN_H_

#include <random>

class RandomGenerator {
    const unsigned int min;
    const unsigned int max;
    static std::random_device rd;
    static std::mt19937 random_generator;
    std::uniform_int_distribution<unsigned int> random_distribution;
  public:
    RandomGenerator(const unsigned int, const unsigned int);
    int getRandom();
};

#endif
