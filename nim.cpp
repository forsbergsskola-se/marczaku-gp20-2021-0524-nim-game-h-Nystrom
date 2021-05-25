
using namespace std;
#include <iostream>
#include <string>

void WriteMatches(int matchAmount) {
    for (int i = 0; i < matchAmount; i++) {
        cout << "I" << flush;
    }
    cout << "" << endl;
}
//TODO: handle input errors
//TODO: Refactor error handling to new method

int DrawMatches(int playerNumber, int matchesLeft) {
    const int maxDraw = 3;
    const int minDraw = 1;
    int drawnMatches;
    cout << "Player" + to_string(playerNumber) + "'s turn to draw matches: " << endl;
    while (true) {
        string errorMessage;
        if (drawnMatches < minDraw || drawnMatches > maxDraw)
            errorMessage = "Needs to be a number between 1 and 3!";
        else if (drawnMatches > matchesLeft)
            errorMessage = "Only " + to_string(matchesLeft) + " matches are left!";
        else
            return drawnMatches;
        cout << errorMessage << endl;
        WriteMatches(matchesLeft);
    }
}
int NextPlayer(int currentPlayer) {
    return currentPlayer == 1 ? 2 : 1;
}
bool Quit() {
    string x;
    cout << "Type x to exit: " << flush;
    cin >> x;
    return x == "x";
}

int main() {
    const int startMatches = 24;

    //TODO: Create a bot option that sums up players pick to 4 each turn. :)
    
    while (true) {
        int matches = startMatches;
        int currentPlayer = 0;
        WriteMatches(matches);
        while (matches > 0) {
            currentPlayer = NextPlayer(currentPlayer);
            matches -= DrawMatches(currentPlayer, matches);
            WriteMatches(matches);
        }
        cout << "Player " + to_string(currentPlayer) + " won!" << endl;
        if (Quit())
            break;
    }
    cout << "Thanks for playing nim! :) " << endl;
    return 0;
}