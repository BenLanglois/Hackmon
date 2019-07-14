#include "hackmon.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
  char cmd;
  string p1;
  string p2;
  unsigned numberBattling;

  char hackmonSelect;
  int hackmonNumber;

  while (cin >> cmd && cmd != 'q') {
    // pregame -----------------------------------------------------------------
    cout << "Now your story begins..." << endl;
    cout << "Hello there! Welcome to the world of HACKMON!" << endl;
    cout << "My name is ROB HACKMAN! People call me the HACKMON PROF!" << endl;
    cout << "This world is inhabited by creatures called HACKMON!" << endl;
    cout << "For some people, HACKMON are pets. Others use them for fights." << endl;
    cout << "Myself...I study HACKMON as a profession. First, what is your name? (player 1)"
    cin >> p1;
    cout << "Right! So your name is" << p1 << "! What is the name of your friend? (player 2)" << endl;
    cin >> p2;

    cout << "Your very own Pokemon legend is about to unfold!" << endl;
    cout <<  "A world of dream and adventures with Pokemon Awaits! Let’s go!" << endl;

    cout << "Would you like to battle 1 v 1 or 2 v 2? (1/2)" << endl;
    while (cin >> numberBattling) {
      if (numberBattling == 1 || numberBattling == 2) break;
      else cout << "...Uh oh, that's not an option. Try again! (1/2)" << endl;
    }

    cout << "...Okay! It’s time to get started!" << endl;

    for (int i=0; i<2; i++) {
      cout << (i==0) ? p1 : p2 << " why don't you pick your Hackmon! You can choose 6 in your party." << endl;
      cout << "You can either select a Hackmon from our Hackerdex or create your own!" << endl;

      for (int j=0; j<6; j++) {
        cout << "For Hackmon #" << i+1 << ", would you like to see the Hackerdex (h) or create your own (o)? (h/o)" << endl;

        while (cin >> hackmonSelect) {
          if (hackmonSelect == 'h' || hackmonSelect == 'o') break;
          else cout << "...Uh oh, that's not an option. Try again! (h/o)" << endl;
        }

        if (hackmonSelect == 'h') {
          // print out Hackerdex with numbers beside it

          cout << "Which Hackmon would you like to select? (1 <= # <= 20)" << endl;
          while (cin >> hackmonNumber) {
            if (hackmonNumber > 0 && hackmonNumber < 21) break;
            else cout << "...Uh oh, that's not an option. Try again! (1 <= # <= 20)" << endl;
          }

          cout << "Great! " << /* hackerdex[hackmonNumber].name */ << "has been added to your party." << endl;

        }
        else if (hackmonSelect == 'o') {


          cout << "Great! " << /* hackerdex[hackmonNumber].name */ << "has been added to your party." << endl;
        }
      }
    }

    // each player pick hackmon
    //     -> option to create own hackmon


    // battle ------------------------------------------------------------------
    // show players all chosen hackmon
    // players choose starting pokemon

    // loop (check if all pokemon of one player have fainted)
      // choose move/use item/swap for each hackmon
      // implement swap first
      // then items
      // then move - order based on hackmon speed
      // output active hackmon stats
    // output winner


    // postgame ----------------------------------------------------------------
    // option to play again (y/n)
    // keep same hackmon (y/n)
    // back to beginming of loop
  }
}

// cout << "" << endl;
