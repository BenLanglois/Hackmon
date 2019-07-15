#ifndef GAME_CONSTANTS_H_
#define GAME_CONSTANTS_H_

#include <map>
#include <vector>
#include <string>
#include "type.h"
#include "hackmon.h"
#include "move.h"
#include "statMove.h"
#include "mobilityMove.h"
#include "debuffMove.h"
#include "family.h"
#include "stats.h"
#include "species.h"

// Hackmon Type to String
const std::map<Type, std::string> typeString = {
  {NORMAL, "Normal"},
  {FIRE, "Fire"},
  {WATER, "Water"},
  {ELECTRIC, "Electric"},
  {GRASS, "Grass"},
  {FIGHTING, "Fighting"},
  {GROUND, "Ground"},
  {PSYCHIC, "Psychic"}
};

// Hackerdex
const std::map<Type, std::vector<Species>> hackerdex = {
  { NORMAL,
    std::vector<Species> {
      Species(std::string("Brown Puppy"),
        specialMoveList.at("Brown Puppy"),
        Stats(90, 6, 5, 8),
        std::vector<Family>{Family(NORMAL)}),
      Species(std::string("Sleepy Sloth"),
        specialMoveList.at("Sleepy Sloth"),
        Stats(130, 5, 4, 3),
        std::vector<Family>{Family(NORMAL)})}
  },
  { FIRE,
    std::vector<Species> {
      Species(std::string("Spicy Lizard"),
        specialMoveList.at("Spicy Lizard"),
        Stats(120, 7, 5, 7),
        std::vector<Family>{Family(FIRE)}),   
      Species(std::string("Flaming Dog"),
        specialMoveList.at("Flaming Dog"),
        Stats(140, 8, 6, 7),
        std::vector<Family>{Family(FIRE)})}
  },
  { WATER,
    std::vector<Species> {  
      Species(std::string("Moist Turtle"),
        specialMoveList.at("Moist Turtle"),
        Stats(120, 6, 6, 8),
        std::vector<Family>{Family(WATER)}),   
      Species(std::string("Slow Duck"),
        specialMoveList.at("Slow Duck"),
        Stats(100, 4, 6, 4),
        std::vector<Family>{Family(WATER)})}
  },
  { ELECTRIC,
    std::vector<Species> {
      Species(std::string("Sparky Mouse"),
        specialMoveList.at("Sparky Mouse"),
        Stats(150, 7, 7, 7),
        std::vector<Family>{Family(ELECTRIC)}),   
      Species(std::string("Exploding Orb"),
        specialMoveList.at("Exploding Orb"),
        Stats(140, 8, 2, 5),
        std::vector<Family>{Family(ELECTRIC)})}
  },
  { GRASS,
    std::vector<Species> {
      Species(std::string("Bulb Dinosaur"),
        specialMoveList.at("Bulb Dinosaur"),
        Stats(120, 5, 8, 7),
        std::vector<Family>{Family(GRASS)}),   
      Species(std::string("Dancing Flower"),
        specialMoveList.at("Dancing Flower"),
        Stats(100, 5, 5, 9),
        std::vector<Family>{Family(GRASS)})}
  },
  { FIGHTING, 
    std::vector<Species> {
      Species(std::string("Karate Kid"),
        specialMoveList.at("Karate Kid"),
        Stats(130, 8, 7, 7),
        std::vector<Family>{Family(FIGHTING)}),   
      Species(std::string("Monkey Man"),
        specialMoveList.at("Monkey Man"),
        Stats(170, 6, 5, 8),
        std::vector<Family>{Family(FIGHTING)})}
  },
  { GROUND,
    std::vector<Species> {
      Species(std::string("Rock Guy"),
        specialMoveList.at("Rock Guy"),
        Stats(120, 5, 9, 6),
        std::vector<Family>{Family(GROUND)}),   
      Species(std::string("Armless Groundhog"),
        specialMoveList.at("Armless Groundhog"),
        Stats(150, 6, 6, 6),
        std::vector<Family>{Family(GROUND)})}
  },
  { PSYCHIC,  
    std::vector<Species> {
      Species(std::string("Spoon Wizard"),
        specialMoveList.at("Spoon Wizard"),
        Stats(180, 7, 5, 6),
        std::vector<Family>{Family(PSYCHIC)}),   
      Species(std::string("Voodoo Anteater"),
        specialMoveList.at("Voodoo Anteater"),
        Stats(140, 5, 8, 7),
        std::vector<Family>{Family(PSYCHIC)})}
  }
};

// Move List
// std::map<std::string, Move> specialMoveList = {
//   { std::string("Brown Puppy"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Sleepy Sloth"),
//     MobilityMove(std::string("Yawn"), SINGLE, 100, Family(NORMAL), )},
//   { std::string("Spicy Lizard"),
//     // 
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Flaming Dog"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Moist Turtle"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Slow Duck"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Sparky Mouse"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Exploding Orb"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Bulb Dinosaur"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Dancing Flower"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Karate Kid"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Monkey Man"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Rock Guy"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Armless Groundhog"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Spoon Wizard"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)},
//   { std::string("Voodoo Anteater"),
//     StatMove(std::string("Tail Whip"), SINGLE, 100, Family(NORMAL), DEFENSE, 1)}
// };

// normal
// - Brown Puppy
// - Sleepy Sloth
// fire
// - Spicy Lizard
// - Flaming Dog
// water
// - Moist Turtle
// - Slow Duck
// electric
// - Sparky Mouse
// - Exploding Orb
// grass
// - Bulb Dinosaur
// - Dancing Flower
// fighting
// - Karate Kid
// - Monkey Man
// ground
// - Rock Guy
// - Armless Groundhog
// psychic
// - Spoon Wizard
// - Voodoo Anteater
// Special Move List
#endif