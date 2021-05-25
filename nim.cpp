
using namespace std;
#include <iostream>
#include <string>
#include <limits>

void WriteMatches(int matchAmount) {
    for (int i = 0; i < matchAmount; i++) {
        cout << "I" << flush;
    }
    cout << "" << endl;
}
//TODO: handle input errors
//TODO: Refactor error handling to new method
int BotDrawMatches(int matchesLeft){
    int value = matchesLeft % 4;
    cout << "Player2's turn: bot picked: " + to_string(value) << endl;
    return value;
}
int DrawMatches(int playerNumber, int matchesLeft) {
    const int maxDraw = 3;
    const int minDraw = 1;
    int drawnMatches;
    cout << "Player" + to_string(playerNumber) + "'s turn to draw matches: " << endl;
    while (true) {
        string errorMessage;
        if(cin >> drawnMatches){
            if (drawnMatches < minDraw || drawnMatches > maxDraw)
                errorMessage = "Needs to be a number between 1 and 3!";
            else if (drawnMatches > matchesLeft)
                errorMessage = "Only " + to_string(matchesLeft) + " matches are left!";
            else
                return drawnMatches;
        }else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            drawnMatches = 0;
            errorMessage = "Needs to be a number between 1 and 3!";
        }
        
        cout << errorMessage << endl;
        WriteMatches(matchesLeft);
    }
}
int NextPlayer(int currentPlayer) {
    return currentPlayer == 1 ? 2 : 1;
}
bool InputCheck(string valueCheck, string message) {
    string inputValue;
    cout << message << endl;
    cin >> inputValue;
    return inputValue == valueCheck;
}

int main() {
    const int startMatches = 24;
    while (true) {
        bool bot = InputCheck("b", "vs bot: b, pvp: other");
        int matches = startMatches;
        int currentPlayer = 0;
        WriteMatches(matches);
        while (matches > 0) {
            currentPlayer = NextPlayer(currentPlayer);
            if(bot && currentPlayer == 2){
                matches -= BotDrawMatches(matches);
            }
            else
            matches -= DrawMatches(currentPlayer, matches);
            WriteMatches(matches);
        }
        cout << "Player " + to_string(currentPlayer) + " won!" << endl;
        if (InputCheck("x", "Quit: x"))
            break;
    }
    cout << "Thanks for playing nim! :) " << endl;
    return 0;
}