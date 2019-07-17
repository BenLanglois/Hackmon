#include <map>
#include <tuple>
#include <vector>
#include <list>

class Action;
class Player;

class ActionQueue {
  std::map<const int, std::list<std::tuple<Action * const, Player * const, const std::vector<size_t>>>> theQueue;
public:
  ActionQueue();
  void push(const int, Action *, Player *, const std::vector<size_t>);
  bool empty();
  void doNextAction();
};
