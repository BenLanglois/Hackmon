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
std::map<StatName, std::string> mobilityString = {
  {MOBILE, "Mobile"},
  {CONFUSION, "Confusion"},
  {PARALYSIS, "Paralysis"},
  {SLEEP, "Sleep"}
};

// Mobility to String verb
std::map<StatName, std::string> mobilityStringVerb = {
  {MOBILE, "Mobile"},
  {CONFUSION, "Confused"},
  {PARALYSIS, "Paralyzed"},
  {SLEEP, "Sleeping"}
};

#endif
