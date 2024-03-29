#include <map>
#include <tuple>
#include <vector>
#include <list>

#include "actionQueue.h"
#include "action.h"
#include "player.h"
#include "randomGen.h"

using namespace std;

ActionQueue::ActionQueue() {}

void ActionQueue::push(const int priority, Action * const action, Player * const player, const vector<size_t> targets) {
  theQueue[priority].emplace_back(tuple<Action * const, Player * const, const vector<size_t>> {action, player, targets});
}

bool ActionQueue::isEmpty() {
  return theQueue.empty();
}

void ActionQueue::doNextAction() {
  list<tuple<Action * const, Player * const, const vector<size_t>>> &highestPriority = theQueue.rbegin()->second;
  RandomGenerator rng {0, static_cast<unsigned>(highestPriority.size()-1)};
  unsigned actionIndex = rng.getRandom();
  auto actionIter = highestPriority.begin();
  for (size_t i = 0; i < actionIndex; ++i) {
    ++actionIter;
  }
  tuple<Action * const, Player * const, const vector<size_t>> nextAction = *actionIter;
  get<0>(nextAction)->doAction(*get<1>(nextAction), get<2>(nextAction));
  highestPriority.erase(actionIter);
  if (highestPriority.size() == 0) {
    theQueue.erase(theQueue.rbegin()->first);
  }
}
