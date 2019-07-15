#include "randomGen.h"
#include <iostream>

using namespace std;

random_device RandomGenerator::rd {};
mt19937 RandomGenerator::random_generator {rd()};

RandomGenerator::RandomGenerator(const unsigned min_, const unsigned max_) : min{min_}, max{max_},
  random_distribution{uniform_int_distribution<unsigned> {min, max}} {

}

unsigned RandomGenerator::getRandom() {
  return random_distribution(random_generator);
}
