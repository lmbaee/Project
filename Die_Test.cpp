#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Die.h"

using namespace std;

int main() {
  Die die(6); // create a six-sided die
  int userTotal = 0, computerTotal = 0; // initialize total scores to 0

  cout << "Let's play a game of 21!\n\n";
  char playAgain = 'y';

  while (playAgain == 'y' && userTotal < 21 && computerTotal < 21) {
    cout << "-----------------------------------\n";
    cout << "Would you like to roll the dice?\n";
    cout << "Enter Y for yes or N for no: ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
  int userRoll = die.roll(); // roll the die for the user
  userTotal += userRoll; // update user's total score by adding the roll result
  cout << "\nYou rolled a " << userRoll << "!\n"; // output the user's roll result
  cout << "Your total is now " << userTotal << ".\n"; // output the updated total score

  if (userTotal >= 21) { // if the user has reached 21 or more
    break; // exit the loop
  }

  int computerRoll = die.roll(); // roll the die for the computer
  computerTotal += computerRoll; // update computer's total score by adding the roll result
  cout << "\nThe computer rolled a " << computerRoll << "!\n"; // output the computer's roll result
  cout << "The computer's total is now " << computerTotal << ".\n"; // output the updated total score

  if (computerTotal >= 21) { // if the computer has reached 21 or more
    break; // exit the loop
  }
} else if (choice == 'n') { // if the user chooses not to roll
  break; // exit the loop
} else { // if the user inputs anything other than 'y' or 'n'
  cout << "Invalid input. Please enter Y or N.\n"; // output an error message
}
  }

  cout << "-----------------------------------\n";
  cout << "The computer had " << computerTotal << " points.\n";
  cout << "You had " << userTotal << " points.\n\n";

  if (userTotal > 21) {
    cout << "Sorry, you went over 21. The computer wins!\n";
  } else if (computerTotal > 21) {
    cout << "Congratulations! The computer went over 21, you win!\n";
  } else if (userTotal > computerTotal) {
    cout << "Congratulations! You won!\n";
  } else if (userTotal < computerTotal) {
    cout << "Sorry, you lost. The computer wins!\n";
  } else {
    cout << "It's a tie!\n";
  }

  cout << "Game Over\n";
  return 0;
}
