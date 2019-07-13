#include "randomGen.h"
#include <iostream>

using namespace std;

RandomGenerator::RandomGenerator(const unsigned int min_, const unsigned int max_) : min{min_}, max{max_} {
  random_generator = mt19937 {rd()};
  random_distribution = uniform_int_distribution<unsigned int> {min, max};
}

int RandomGenerator::getRandom() {
  return random_distribution(random_generator);
}

int main() {
  RandomGenerator rng(1,10);
  for(int i = 0; i < 10; i++) {
    cout << rng.getRandom() << endl;
  }
}