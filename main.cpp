#include <QCoreApplication>
#include <iostream>
#include "card_game.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Get player name from input
    string playerName;
    cout << "Enter name: ";
    getline(cin, playerName);

    // Play game loop, after game finishes repeat if user selects play again
    bool playAgain = true;
    while (playAgain){
        CardGame game(playerName.empty() ? "Player" : playerName);
        cout << "\n*******************************\n" << endl;
        game.play();
        cout << "\n*******************************\n" << endl;

        string input;
        cout << "Would you like to play again? (y/n): " << endl;
        while(true){
            getline(cin, input);
            if (input == "y"){
                playAgain = true;
                break;
            } else if (input == "n"){
                playAgain = false;
                break;
            } else{
                cout << "Please enter a valid input (y=yes, n=no)" << endl;
            }
        }
    }

    cout << "\nThanks for playing!" << endl;
    return a.exec();
}
