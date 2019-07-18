#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

#include "hackmon.h"
#include "player.h"
#include "move.h"
#include "species.h"
#include "stats.h"
#include "gameConstants.h"
#include "globalConstants.h"
#include "actionQueue.h"
#include "switch.h"

using namespace std;

const string red("\033[1;31m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");
const string purple("\033[1;35m");
const string white("\033[1;37m");
const string reset("\033[0m");
const string clearScreen("\033c");

template<typename T>
void getValidValueRange(T& inVar, T rangeMin, T rangeMax) {
  while (true) {
    if ((cin >> inVar) && inVar >= rangeMin && inVar <= rangeMax) {
      break;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "...Uh oh, that's not an option. Try again! (" << rangeMin << "<= # <= " << rangeMax << ")" << endl;
  }
}

template <typename T>
bool _isOneOf(T key, T first) {
  return key == first;
}

template <typename T, typename... Rest>
bool _isOneOf(T key, T first, Rest... rest) {
  return key == first ? true : _isOneOf(key, rest...);
}

template <typename T>
void _printValues(T first) {
  cout << first;
}

template <typename T, typename... Rest>
void _printValues(T first, Rest... rest) {
  cout << first << "/";
  _printValues(rest...);
}

template <typename T, typename... Rest>
T getValidValueOneOf(Rest... values) {
  T inVar;
  while (cin >> inVar) {
    if (_isOneOf(inVar, values...)) break;
    else cout << "...Uh oh, that's not an option. Try again! (";
    _printValues(values...); // print out valid values
    cout << ")" << endl;
  }
  return inVar;
}

void printTypeList() {
  cout << magenta;
  int i = 0;
  for (auto const& type : typeString) {
    cout << ++i << ". " << type.second << endl;
  }
  cout << cyan;
}

void printMoveList() {
  cout << magenta;
  int i = 0;
  for (auto& move : moveList) {
    if (i < 9) cout << " ";
    cout << ++i << ". ";
    move->printMove();
    cout << endl;
  }
  cout << cyan;
}

void printItemList() {
  cout << magenta;
  int i = 0;
  for (auto& item : itemList) {
    cout << ++i << ". ";
    item->printItem();
    cout << endl;
  }
  cout << cyan;
}

void printHackerdexAtType(int t) {
  cout << magenta;
  int i = 0;
  vector<Species> speciesForType = hackerdex.at((Type)t);
  for (auto& sp : speciesForType) {
    cout << ++i << ". ";
    sp.printSpecies();
    cout << endl;
  }
  cout << cyan;
}

string trimString(string &s) {
  size_t start = s.find_first_not_of(" ");
  size_t end = s.find_last_not_of(" ");
  return s.substr(start, end-start+1);
}

int main() {
  fillSpecialMoveList();
  fillMoveList();
  fillItemList();
  fillHackerdex();

  string name1;
  string name2;
  vector<unique_ptr<Hackmon>> party1;
  vector<unique_ptr<Hackmon>> party2;
  vector<unique_ptr<Item>> items1;
  vector<unique_ptr<Item>> items2;

  char visuals;

  bool gameLoop = true;
  bool battleLoop = true;
  bool playerLoop = true;

  while (gameLoop) {
    // pregame -----------------------------------------------------------------
    cout << clearScreen;
    cout << cyan << "Now your story begins..." << endl << endl;
    cout << "Hello there! Welcome to the world of " << white << "HACKMON" << cyan << "!" << endl << endl;
    cout << "My name is ROB HACKMAN! People call me the " << white << "HACKMON" << cyan << " PROF!" << endl; // FIXME: add timers to these statementd
    cout << "This world is inhabited by creatures called " << white << "HACKMON" << cyan << "!" << endl << endl;
    cout << "For some people, " << white << "HACKMON" << cyan << " are pets. Others use them for fights." << endl;
    cout << "Myself...I study " << white << "HACKMON" << cyan << " as a profession." << endl << endl;
    cout << "First, what is your name? " << yellow << "(player 1)" << reset << endl;
    getline(cin, name1);
    name1 = trimString(name1);
    cout << endl << cyan << "Right! So your name is " << red << name1;
    cout << cyan << "! What is the name of your friend? " << yellow << "(player 2)" << reset << endl;
    getline(cin, name2);
    name2 = trimString(name2);
    cout << cyan << "Welcome " << red << name2 << cyan << "!" << endl;
    cout << endl;

    cout << cyan << "Would you like to read an explanation about the mechanics of the game? " << yellow << "(y/n)" << reset << endl;
    if (getValidValueOneOf<char>('y', 'n') == 'y') {
      cout << clearScreen;
      cout << cyan << "HOW TO PLAY ----------------------------------------------------------------------------------------" << endl;
      cout << endl;
      cout << cyan << "You win the game by causing all " << white << "HACKMON" << cyan << " on your opponent's team to faint. Both players will select a team of " << white << "HACKMON" << cyan << " to" << endl;
      cout << cyan << "battle against each other. You will also select a list of moves for each of your " << white << "HACKMON" << cyan << " to learn. These moves can" << endl;
      cout << cyan << "either lower the stats of an enemy " << white << "HACKMON" << cyan << ", inflict a mobility effect upon them, or inflict a debuff upon them. Each" << endl;
      cout << cyan << "" << white << "HACKMON" << cyan << " has four stats:" << endl;
      cout << cyan << "- HP: The amount of health the " << white << "HACKMON" << cyan << " has left. The " << white << "HACKMON" << cyan << " will faint if its HP drops to 0." << endl;
      cout << cyan << "- ATTACK: Affects the " << white << "HACKMON" << cyan << "'s damage-dealing moves and is used to determine how much the target's HP will drop." << endl;
      cout << cyan << "- DEFENSE: Represents how resistant the " << white << "HACKMON" << cyan << " is to losing HP." << endl;
      cout << cyan << "- SPEED: Determines the order in which " << white << "HACKMON" << cyan << " will move in each round." << endl;
      cout << cyan << endl;
      cout << cyan << "If a " << white << "HACKMON" << cyan << " is inflicted by a mobility effect, then it may be unable to make a move on their turn. There are three" << endl;
      cout << cyan << "types of mobility effects:" << endl;
      cout << cyan << "- SLEEP: The " << white << "HACKMON" << cyan << " will be unable to move until it wakes up. SLEEP can last for up to 4 turns." << endl;
      cout << cyan << "- PARALYSIS: The " << white << "HACKMON" << cyan << " may be unable to move on its turn. PARALYSIS will last forever unless it is cured." << endl;
      cout << cyan << "- CONFUSION: The " << white << "HACKMON" << cyan << " may hurt itself on its turn, preventing it from moving. CONFUSION will last for 5 turns." << endl;
      cout << cyan << endl;
      cout << cyan << "A debuff will lower the stats of a " << white << "HACKMON" << cyan << " until it is cured or until the " << white << "HACKMON" << cyan << " is inflicted by another debuff. There" << endl;
      cout << cyan << "are three types of debuffs:" << endl;
      cout << cyan << "- POISONED: Lowers the " << white << "HACKMON" << cyan << "'s ATTACK." << endl;
      cout << cyan << "- BURNED: Lowers the " << white << "HACKMON" << cyan << "'s DEFENSE." << endl;
      cout << cyan << "- FROZEN: Lowers the " << white << "HACKMON" << cyan << "'s SPEED." << endl;
      cout << cyan << endl;
      cout << cyan << "Before the game starts, you will also get to choose items which you can use on your turn instead of making a move." << endl;
      cout << cyan << "Unlike moves, items affect your own " << white << "HACKMON" << cyan << ". Items can raise the stat of a " << white << "HACKMON" << cyan << " or remove a mobility effect or debuff" << endl;
      cout << cyan << "from a " << white << "HACKMON" << cyan << "." << endl;
      cout << cyan << endl;
      cout << cyan << "Items and moves also have a scope which determines if they will affect one " << white << "HACKMON" << cyan << " or all " << white << "HACKMON" << cyan << " in the party." << endl;
      cout << endl;
      cout << cyan << "----------------------------------------------------------------------------------------------------" << endl;
    }

    cout << endl;
    cout << cyan << "Your very own " << white << "HACKMON" << cyan << " legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with " << white << "HACKMON" << cyan << " Awaits! Let’s go!" << reset << endl;
    cout << endl;

    while (playerLoop) {
      party1.clear();
      party2.clear();
      items1.clear();
      items2.clear();

      cout << cyan << endl << "Would you like the added bonus of " << white << "HACKMON" << cyan << " visuals? " << yellow << "(y/n)" << reset << endl;
      visuals = getValidValueOneOf<char>('y', 'n');

      cout << cyan << endl << "Would you like to battle 1 vs 1 or 2 vs 2? " << yellow << "(1/2)" << reset << endl;
      numberBattling = getValidValueOneOf<int>(1, 2);

      cout << cyan << "...Okay! It’s time to get started!" << endl;

      for (int p=0; p<2; p++) {
        // reset party unique pointers
        int itemNumber;

        cout << endl << endl << red << (p==0 ? name1 : name2);
        cout << cyan << " why don't you pick your " << white << "HACKMON" << cyan << "! You can choose " << numberParty << " in your party." << endl;
        cout << "You can either select a " << white << "HACKMON" << cyan << " from our Hackerdex or create your own!" << endl;

        for (int h=0; h<numberParty; h++) {
          char hackmonSelect;
          int hackmonType;
          int hackmonNumber;
          char wantNameHackmon;
          string hackmonName;
          int hackmonMove;
          vector<unique_ptr<Move>> hackmonMoves;

          string newHackmonSpecies;
          string newHackmonName;
          vector<Family> newHackmonFamily;
          int newHackmonSpecialMove;
          int newHackmonHp;
          int newHackmonAttack;
          int newHackmonDefense;
          int newHackmonSpeed;

          Species* speciesToUse;

          cout << endl << "For " << white << "HACKMON" << cyan << " #" << h+1 << ", would you like to see the Hackerdex (h) or create your own (o)? ";
          cout << yellow << "(h/o)" << reset << endl;
          hackmonSelect = getValidValueOneOf<char>('h', 'o');

          cout << endl << cyan << "Here is a list of the 8 " << white << "HACKMON" << cyan << " types:" << endl;
          printTypeList();
          cout << "Which type would you like your " << white << "HACKMON" << cyan << " to be? " << yellow << "(1 <= # <= 8)" << reset << endl;
          getValidValueRange(hackmonType, 1, 8);
          --hackmonType;

          if (hackmonSelect == 'h') {
            cout << endl << cyan << "Here is a list of the " << white << "HACKMON" << cyan << " of type " << typeString.at((Type)hackmonType) << "." << endl;
            printHackerdexAtType(hackmonType);
            cout << "Which " << white << "HACKMON" << cyan << " would you like to select? " << yellow << "(1 <= # <= " << hackerdex.at((Type)hackmonType).size() << ")" << reset << endl;
            getValidValueRange(hackmonNumber, 1, (int)hackerdex.at((Type)hackmonType).size());
            hackmonNumber--;
          } else {

            newHackmonFamily.emplace_back(Family((Type)hackmonType)); // FIXME: remove casting
            cout << cyan << "What would you like the name of your species to be?" << reset << endl;
            getline(cin, newHackmonSpecies);
            newHackmonSpecies = trimString(newHackmonSpecies);
          }

          cout << endl << cyan << "Awesome! Would you like to name your " << white << "HACKMON" << cyan << "? " << yellow << "(y/n)" << reset << endl;
          wantNameHackmon = getValidValueOneOf<char>('y', 'n');

          if (wantNameHackmon == 'y') {
            cout << cyan << "What would you like the name of your " << white << "HACKMON" << cyan << " to be?" << reset << endl;
            getline(cin, hackmonName);
            hackmonName = trimString(hackmonName);
          }

          int numberOfMovesToSelect = (hackmonSelect == 'h') ? 3 : 4;
          cout << endl << cyan << "Here is a list of the " << moveList.size() << " " << white << "HACKMON" << cyan << " moves:" << endl;
          printMoveList();
          cout << "Which moves would you like your " << white << "HACKMON" << cyan << " to have? Please type " << numberOfMovesToSelect;
          cout  << " numbers separated by spaces " << yellow << "(1 <= # <= " << moveList.size() << ")" << reset << endl;
          for (int k=0; k<3; k++) {
            getValidValueRange(hackmonMove, 1, (int)moveList.size()); // FIXME: remove casting
            hackmonMoves.emplace_back(moveList.at(hackmonMove-1)->clone());
          }

          if (numberOfMovesToSelect == 4) {
            getValidValueRange(newHackmonSpecialMove, 1, (int)moveList.size()); // FIXME: remove casting
            --newHackmonSpecialMove; // reindex to 0
          }

          if (hackmonSelect == 'o') {
            cout << endl << cyan << "Now lets set your " << white << "HACKMON" << cyan << " stats." << endl;
            cout << "What would you like your maximum health points(HP) to be? " << yellow << "(1 <= # <= 25)" << reset << endl;
            getValidValueRange(newHackmonHp, 1, 25);

            cout << cyan << "What would you like your base attack level to be? " << yellow << "(1 <= # <= 10)" << reset << endl;
            getValidValueRange(newHackmonAttack, 1, 10);

            cout << cyan << "What would you like your base defense level to be? " << yellow << "(1 <= # <= 10)" << reset << endl;
            getValidValueRange(newHackmonDefense, 1, 10);

            cout << cyan << "What would you like your base speed level to be? " << yellow << "(1 <= # <= 10)" << reset << endl;
            getValidValueRange(newHackmonSpeed, 1, 10);

            Species createdHackmonSpecies(
              newHackmonSpecies,
              *moveList.at(newHackmonSpecialMove),
              Stats(newHackmonHp, newHackmonAttack, newHackmonDefense, newHackmonSpeed),
              newHackmonFamily
            );

            hackerdex.at((Type)hackmonType).emplace_back(createdHackmonSpecies);
            speciesToUse = &hackerdex.at((Type)hackmonType).back(); // FIXME: get from species list
          } else {
            speciesToUse = &hackerdex.at((Type)hackmonType).at(hackmonNumber);
          }

          unique_ptr<Hackmon> newHackmon = speciesToUse->createHackmon(move(hackmonMoves), hackmonName);

          if (p==0) party1.emplace_back(move(newHackmon)); else party2.emplace_back(move(newHackmon));
          cout << endl << cyan << "Great! " << magenta << (p==0 ? party1.back()->name : party2.back()->name) << cyan << " has been added to your party!" << endl << endl;
        }

        cout << cyan << "Now, lets select some items to put in your bag! Here is a list of the available items:" << endl;
        printItemList();
        cout << "Which items would you like to select? Please type " << numberOfItems;
        cout  << " numbers separated by spaces " << yellow << "(1 <= # <= " << itemList.size() << ")" << reset << endl;
        for (int k=0; k<numberOfItems; k++) {
          getValidValueRange(itemNumber, 1, (int)itemList.size()); // FIXME: remove cast
          if (p==0) items1.emplace_back(itemList.at(itemNumber-1)->clone()); else items2.emplace_back(itemList.at(itemNumber-1)->clone());
        }
      }

      Player p1(name1, move(party1), move(items1));
      Player p2(name2, move(party2), move(items2));

      while (battleLoop) {
        // battle ------------------------------------------------------------------
        cout << endl << cyan << "It looks like you two trainers are ready to battle!" << endl; // FIXME: add timers to these statementd

        // players choose starting pokemon
        int inBattleIndex;
        vector<int> inBattleIndexes;

        for (int p=0; p<2; p++) {
          Player &curPlayer = (p==0 ? p1 : p2);

          cout << cyan << "Now " << red << curPlayer.name << cyan << ", lets choose your starting " << white << "HACKMON" << cyan << "!" << endl << endl;
          cout << "Lets see which " << white << "HACKMON" << cyan << " you both have chosen!" << endl;
          // show players all chosen hackmon

          cout << magenta;
          p1.printParty();
          p2.printParty();
          cout << cyan;

          cout << red << curPlayer.name << cyan << " please select " << numberBattling << " " << white << "HACKMON" << cyan << " from your list above" << (numberBattling > 1 ? " (separated by spaces)." : ".") << reset << endl;
          for (unsigned m=0; m<numberBattling; m++) {
            getValidValueRange(inBattleIndex, 1, numberParty);
            inBattleIndexes.emplace_back(--inBattleIndex);
          }
          cout << endl;

          // make sure first (numberBattling) indexes in array are the starting hackmon
          for (unsigned m=0; m<numberBattling; m++) {
            if ((unsigned)inBattleIndexes.at(m) != m) {
              curPlayer.swapHackmon(m, inBattleIndexes.at(m));
            }
          }

          cout << clearScreen;
        }

        // loop (check if all pokemon of one player have fainted)
        int loopCounter = 0;
        cout << endl << yellow << "Time to battle!" << endl << endl;

        const int itemPriority = 99;
        const int switchPriority = 100; // We all know that numbers stop at 100

        // Need this to store the switch actions somewhere
        Switch theSwitch;

        while (p1.partyAlive() && p2.partyAlive()) {
          cout << white << "------------ ROUND " << ++loopCounter << " ------------" << endl << endl;

          // The priority queue of actions
          ActionQueue actionQueue;
          // The list of actions to be used this round
          vector<unique_ptr<Item>> itemsThisRound;

          // choose move/use item/swap for each hackmon
          for (int p=0; p<2; ++p) {
            Player &currPlayer = (p == 0 ? p1 : p2);
            Player &otherPlayer = (p == 0 ? p2 : p1);

            for (unsigned h=0; h<numberBattling; ++h) {
              if (!currPlayer.isAlive(h)) {
                continue;
              }
              Hackmon &currHackmon = *currPlayer.party.at(h);
              cout << red << currPlayer.name << cyan << ", please select for " << magenta << currHackmon.name << endl << endl;

              if (visuals == 'y' && currHackmon.art.size()) {
                cout << white;
                for (auto const& l : currHackmon.art) {
                  cout << l;
                }
                cout << endl << magenta;
              }

              cout << currHackmon.name <<  cyan << "'s stats:" << magenta << endl;
              currHackmon.stats.printStats();
              cout << magenta << "   MOBILITY: " << mobilityStringVerb.at(currHackmon.mobility->name());
              cout << "   DEBUFF: " << debuffString.at(currHackmon.debuff.name) << endl << endl;

              char action;
              if (currPlayer.items.size() > 0) {
                // Able to use items
                if (currPlayer.nextAlive < static_cast<unsigned>(numberParty)) {
                  // Able to switch
                  cout << cyan << "Will you make a move against your opponent, use an item, "
                       << "or swap out your " << white << "HACKMON" << cyan << " with another in your party? " << yellow << "(m/i/s)" << reset << endl;
                  action = getValidValueOneOf<char>('m', 'i', 's');
                } else {
                  // Unable to switch
                  cout << cyan << "Will you make a move against your opponent or use an item? " << yellow << "(m/i) " << reset << endl;
                  action = getValidValueOneOf<char>('m', 'i');
                }
              } else {
                // Unable to use items
                if (currPlayer.nextAlive < static_cast<unsigned>(numberParty)) {
                  // Able to switch
                  cout << cyan << "Will you make a move against your opponent "
                       << "or swap out your " << white << "HACKMON" << cyan << " with another in your party? " << yellow << "(m/s)" << reset << endl;
                  action = getValidValueOneOf<char>('m', 's');
                } else {
                  // Unable to switch
                  action = 'm';
                }
              }


              if (action == 'm') {
                  // Hackmon does a move
                  cout << endl << cyan << "Here is a list of the available moves:" << magenta << endl;
                  for (size_t moveIndex = 0; moveIndex < currHackmon.moves.size(); ++moveIndex) {
                    // Give one-indexed list of moves
                    cout << moveIndex+1 << ": ";
                    currHackmon.moves.at(moveIndex)->printMove();
                    cout << endl;
                  }
                  cout << reset;

                  // pick one from list
                  size_t selectedMoveIndex;
                  getValidValueRange<size_t>(selectedMoveIndex, 1, currHackmon.moves.size());
                  --selectedMoveIndex; // Make zero-indexed

                  // Hard-coded move logic for 1v1 and 2v2 battles starts here ------------
                  Move &selectedMove = *currHackmon.moves.at(selectedMoveIndex);
                  vector<size_t> targets;

                  if (numberBattling == 1) {
                    targets.emplace_back(0);
                  } else {
                    if (selectedMove.scope == SINGLE) {
                      // select targets (if needed)
                      if (!otherPlayer.isAlive(0)) {
                        targets.emplace_back(1);
                      } else if (!otherPlayer.isAlive(1)) {
                        targets.emplace_back(0);
                      } else {
                        // Both possible targets are still alive
                        cout << cyan << "Which enemy should " << magenta << currHackmon.name << cyan << " target? " << yellow << "(1/2)" << magenta << endl;
                        cout << "1. " << otherPlayer.party.at(0)->name << endl;
                        cout << "2. " << otherPlayer.party.at(1)->name << endl;
                        cout << reset;
                        size_t targetIndex;
                        getValidValueRange<size_t>(targetIndex, 1, 2);
                        --targetIndex;
                        targets.emplace_back(targetIndex);
                      }

                    } else {
                      // attack all targets
                      if (otherPlayer.isAlive(0)) {
                        targets.emplace_back(0);
                      }
                      if (otherPlayer.isAlive(1)) {
                        targets.emplace_back(1);
                      }
                    }
                  }
                  // Hard-coded move logic for 1v1 and 2v2 battles ends here --------------

                  // add to playerMove vector
                  int speed = currHackmon.stats.getStat(SPEED);
                  if (currHackmon.debuff.stat == SPEED) {
                    speed -= currHackmon.debuff.strength;
                  }
                  actionQueue.push(speed, &selectedMove, &otherPlayer, targets);

              } else if (action == 'i') {
                // output list of items
                cout << endl << cyan << "Here is a list of the available items:" << magenta << endl;
                for (size_t index = 0; index < currPlayer.items.size(); ++index) {
                  cout << index + 1 << ". ";
                  currPlayer.items.at(index)->printItem();
                  cout << endl;
                }
                cout << endl << cyan << "Please select a item " << yellow << "(1 <= # <= " << currPlayer.items.size() << ")" << reset << endl;
                size_t selectedItemIndex;
                getValidValueRange<size_t>(selectedItemIndex, 1, currPlayer.items.size());
                --selectedItemIndex; // zero-index

                // Hard-coded item logic for 1v1 and 2v2 battles starts here ------------
                Item &selectedItem = *currPlayer.items.at(selectedItemIndex);
                vector<size_t> targets;

                if (numberBattling == 1) {
                  targets.emplace_back(0);
                } else {
                  if (selectedItem.scope == SINGLE) {
                    // select targets (if needed)
                    if (!currPlayer.isAlive(0)) {
                      targets.emplace_back(1);
                    } else if (!currPlayer.isAlive(1)) {
                      targets.emplace_back(0);
                    } else {
                      // Both possible targets are still alive
                      cout << cyan << "Which " << white << "HACKMON" << cyan << " should receive the item? " << yellow << "(1/2)" << magenta << endl;
                      cout << "1. " << currPlayer.party.at(0)->name << endl;
                      cout << "2. " << currPlayer.party.at(1)->name << endl;
                      cout << reset;
                      size_t targetIndex;
                      getValidValueRange<size_t>(targetIndex, 1, 2);
                      --targetIndex;
                      targets.emplace_back(targetIndex);
                    }
                  } else {
                    // give item to all hackmon
                    if (currPlayer.isAlive(0)) {
                      targets.emplace_back(0);
                    }
                    if (currPlayer.isAlive(1)) {
                      targets.emplace_back(1);
                    }
                  }
                }
                // Hard-coded item logic for 1v1 and 2v2 battles ends here --------------

                // Move item from player's item list to itemsThisRound vector
                itemsThisRound.emplace_back(unique_ptr<Item> {nullptr});
                swap(itemsThisRound.back(), currPlayer.items.at(selectedItemIndex));
                currPlayer.items.erase(currPlayer.items.begin() + selectedItemIndex);
                actionQueue.push(itemPriority, itemsThisRound.back().get(), &currPlayer, targets);

              } else {
                // Switch Hackmon
                cout << cyan << "Which Hackmon will you swap " << magenta << currHackmon.name << cyan << " for?" << endl;
                cout << magenta;
                for (size_t index = 0; index < numberParty - currPlayer.nextAlive; ++index) {
                  cout << index + 1 << ". " << currPlayer.party.at(index + currPlayer.nextAlive)->name << endl;
                }
                cout << reset;
                size_t selectedHackmonIndex;
                getValidValueRange<size_t>(selectedHackmonIndex, 1, numberParty - currPlayer.nextAlive);
                selectedHackmonIndex += currPlayer.nextAlive - 1; // Set to actual index into party vector
                actionQueue.push(switchPriority, &theSwitch, &currPlayer, vector<size_t>{h, selectedHackmonIndex});
              }
            }

            cout << clearScreen;
          }

          // Execute all actions selected by the players
          cout << cyan;
          while (!actionQueue.isEmpty()) {
            actionQueue.doNextAction();
          }

          // output active hackmon stats
          cout << endl << endl;
          cout << white << "--------- ROUND " << loopCounter << " STATS ---------" << endl;
          for (int p=0; p<2; ++p) {
            Player &currPlayer = (p == 0 ? p1 : p2);
            cout << red << currPlayer.name << ":" << magenta << endl;
            for (unsigned h=0; h<numberBattling; ++h) {
              cout << currPlayer.party.at(h)->name << ": ";
              currPlayer.party.at(h)->stats.printStats();
              cout << "   MOBILITY: " << mobilityStringVerb.at(currPlayer.party.at(h)->mobility->name());
              cout << "   DEBUFF: " << debuffString.at(currPlayer.party.at(h)->debuff.name) << endl;
            }
            cout << endl;
          }
          cout << endl << endl;
        }

        // output winner (if winner)
        cout << purple;
        string winner;
        if (!p1.partyAlive()) {
          winner = p2.name;
          p2.hasWon();
        } else {
          winner = p1.name;
          p1.hasWon();
        }
        cout << reset;

        // reset hackmon
        for (int p=0; p<2; ++p) {
          Player &currPlayer = (p == 0 ? p1 : p2);
          for (auto& hackmon : currPlayer.party) {
            hackmon->restore();
          }
        }

        // postgame ----------------------------------------------------------------
        char playAgain;
        char keepHackmon;

        cout << cyan << "ROB HACKMAN here! Congrats to " << red << winner << cyan << " for the win!" << endl; // FIXME: add timers to these statement
        cout << "Here is the current scores:" << endl;
        cout << red << p1.name << ": " << p1.winTotal << endl;
        cout << p2.name << ": " << p2.winTotal << endl << endl;
        cout << cyan << "Would you two trainers like to battle again? " << yellow << "(y/n)" << reset << endl;
        playAgain = getValidValueOneOf<char>('y', 'n');

        if (playAgain == 'y') {
          cout << "Would you like to battle with the same " << white << "HACKMON" << cyan << "? " << yellow << "(y/n)" << reset << endl;
          keepHackmon = getValidValueOneOf<char>('y', 'n');

          if (keepHackmon == 'y') {
            // FIXME: reset Hackmon levels
            battleLoop = true;
          } else {
            battleLoop = false;
            playerLoop = true;
          }
        } else {
          battleLoop = false;
          playerLoop = false;
        }
      }
    }
  }
}
