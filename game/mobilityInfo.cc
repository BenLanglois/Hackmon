#include <map>
#include <string>

#include "mobilityInfo.h"

// Mobility to String
std::map<MobilityName, std::string> mobilityString = {
  {MOBILE, "Mobile"},
  {CONFUSION, "Confusion"},
  {PARALYSIS, "Paralysis"},
  {SLEEP, "Sleep"}
};

// Mobility to String verb
std::map<MobilityName, std::string> mobilityStringVerb = {
  {MOBILE, "Mobile"},
  {CONFUSION, "Confused"},
  {PARALYSIS, "Paralyzed"},
  {SLEEP, "Sleeping"}
};
