#ifndef MOBILITY_INFO_H
#define MOBILITY_INFO_H

#include <map>
#include <string>

enum MobilityName {
  MOBILE,
  CONFUSION,
  PARALYSIS,
  SLEEP
};

// Mobility to String
extern std::map<MobilityName, std::string> mobilityString;

// Mobility to String verb
extern std::map<MobilityName, std::string> mobilityStringVerb;

#endif
