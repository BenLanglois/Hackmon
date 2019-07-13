#include "hackmon.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
  char cmd;
  string p1;
  string p2;

  while (cin >> cmd && cmd != 'q') {
    cout << "Welcome to Hackmon!" << endl;
    cout << "Please enter the name of Player 1:" << endl;
    cin >> p1;
    cout << "Please enter the name of Player 2:" << endl;
    cin >> p2;

    cout << "Excellent! Would you like to battle 1 v 1 or 2 v 2?" << endl;


  }
}
