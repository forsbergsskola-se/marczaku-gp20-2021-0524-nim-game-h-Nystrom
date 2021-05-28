
using namespace std;
#include <iostream>
#include <string>
#include <limits>

    void UpdateMatches(int matchAmount) {
        for (int i = 0; i < matchAmount; i++) {
            cout << "I" << flush;
        }
        cout << "" << endl;
    }
    int BotDrawMatches(int matchesLeft){
        int value = matchesLeft % 4;
        cout << "Player2's turn: bot picked: " + to_string(value) << endl;
        return value;
    }
    int DrawMatches(int playerNumber, int matchesLeft) {
        const int maxDraw = 3;
        const int minDraw = 1;
        int drawnMatches = -1;
        cout << "Player" + to_string(playerNumber) + "'s turn to draw matches: " << endl;
        while (true) {
            string errorMessage;
            cin >> noskipws >>drawnMatches;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if(drawnMatches){
                if (drawnMatches < minDraw || drawnMatches > maxDraw)
                    errorMessage = "Needs to be a number between 1 and 3!";
                else if (drawnMatches > matchesLeft)
                    errorMessage = "Only " + to_string(matchesLeft) + " matches are left!";
                else
                    return drawnMatches;
            }else{
                drawnMatches = -1;
                errorMessage = "Needs to be a number between 1 and 3!";
            }
            cout << errorMessage << endl;
            UpdateMatches(matchesLeft);
        }
    }
    int NextPlayer(int currentPlayer) {
        return currentPlayer == 1 ? 2 : 1;
    }
    bool BooleanInputCheck(string valueCheck, string message) {
        string inputValue;
        cout << message << endl;
        getline(cin, inputValue);
        return inputValue == valueCheck;
    }

    int main() {
        const int startMatches = 24;
        while (true) {
            bool bot = BooleanInputCheck("b", "vs bot: b, pvp: other");
            int matches = startMatches;
            int currentPlayer = 0;
            UpdateMatches(matches);
            while (matches > 0) {
                currentPlayer = NextPlayer(currentPlayer);
                if(bot && currentPlayer == 2){
                    matches -= BotDrawMatches(matches);
                }
                else{
                    matches -= DrawMatches(currentPlayer, matches);
                }
                
                UpdateMatches(matches);
            }
            cout << "Player " + to_string(currentPlayer) + " won!" << endl;
            if (BooleanInputCheck("x", "Quit: x"))
                break;
        }
        cout << "Thanks for playing nim! :) " << endl;
        return 0;
    }