using namespace std;
#include <iostream>
#include <string>
#include <limits>
#include "Bot.h"
#include "CurrentTurn.h"

void CreateTileMap(string tileMap[]){
    for (int i = 0; i <= sizeof(tileMap);i++){
        tileMap[i] = ' ';
    }
}
void UpdateTileMap(string tileMap[], const int rowSize){
    for (int i = 0; i <=  sizeof(tileMap);i++){
        cout << " | " + tileMap[i] << flush;
        const int tempNumber = i + 1;
        if(tempNumber % rowSize == 0){
            cout << " | " << endl;
            cout << "---------------" << endl;
        }
            
    }
}
bool IsTileEmpty(const char tile){
    return tile == ' ';
}
int PickTile(const int currentPlayer, string tileMap[]){
    const int indexAdjuster = 1;
    const int maxIndex = sizeof(tileMap)+indexAdjuster;
    int playerInput = -1;
    
    cout << "Player"+ to_string(currentPlayer) + "'s turn to pick tile 1 to " + to_string(maxIndex) + ": " << endl;
    while (true){
        string errorMessage;
        cin >> noskipws >> playerInput;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(playerInput){
            if(playerInput < 1 || playerInput > maxIndex)
                errorMessage = "Needs to be a number between 1 and " + to_string(maxIndex) + "!";
            else if (!IsTileEmpty(tileMap[playerInput-indexAdjuster][0]))
                errorMessage = "Needs to be an empty tile!";
            else
                return --playerInput;
        }else{
            errorMessage = "Needs to be a number between 1 and " + to_string(maxIndex) + "!";
        }
        cout << errorMessage << endl;
    }
}

int NextPlayer(const int currentPlayer){
    return currentPlayer == 1 ? 2 : 1;
}
char GetTileMarker(const int currentPlayer){
    return currentPlayer == 1 ? 'O' : 'X';
}

bool BooleanInputCheck(const char valueCheck, const string message) {
    string inputValue;
    cout << message << endl;
    getline(cin, inputValue);
    return inputValue[0] == valueCheck;
}
bool DiagonalCheck(const CurrentTurn currentTurn,string tileMap[]){
    const int middleTileValue = 4;
    if(tileMap[middleTileValue][0] == currentTurn.marker && currentTurn.newTileIndex % 2 == 0){
        for (int i = 6; i <= 8; i++){
            if(tileMap[i][0] == currentTurn.marker && tileMap[i%middleTileValue][0] == currentTurn.marker){
                return true;
            }
            ++i;
        }
    }
    return false;
}
bool RowCheck(const CurrentTurn currentTurnData,string tileMap[]){
    const int rowLength = 3;
    for (int i = 0; i < rowLength; i++){
        const int startOfRowIndex = currentTurnData.newTileIndex % rowLength + i * rowLength;
        if(tileMap[startOfRowIndex][0] != currentTurnData.marker)
            break;
        if(i == rowLength-1)
            return true;
    }
    return false;
}

bool ColumnCheck(const CurrentTurn playerTurnData,string tileMap[]){
    const int columnLength = 3;
    for (int i = 0; i < columnLength; i++){
        const int temp = playerTurnData.newTileIndex - playerTurnData.newTileIndex % columnLength + i;
        if(tileMap[temp][0] != playerTurnData.marker)
            break;
        if(i==columnLength-1)
            return true;
    }
    return false;
}

bool HasThreeInARow(const CurrentTurn currentTurnData,string tileMap[]){
    if(DiagonalCheck(currentTurnData, tileMap))
        return true;
    if(RowCheck(currentTurnData, tileMap))
        return true;
    if(ColumnCheck(currentTurnData, tileMap))
        return true;   
    return false;
}
int main(){
    while (true) {
        const int maxSize = 9;
        string tileMap[maxSize];
        CreateTileMap(tileMap);
        const int rowSize = 3;
        const bool isAgainstBot = BooleanInputCheck('b', "vs bot: b, pvp: other");
        int currentPlayer = 0;
        int tileNumber;
        int currentTurn = 1;
        string endOfGameMessage; 
        UpdateTileMap(tileMap, rowSize);
        
        while (true){
            currentPlayer = NextPlayer(currentPlayer);
            if(isAgainstBot && currentPlayer == 2){
                cout << "Bot's turn to pick tile: " << endl;
                auto bot = new Bot();
                tileNumber = bot->PickTile(tileMap);
                delete bot;
            }
            else{
                tileNumber = PickTile(currentPlayer, tileMap);
            }
            const char playerMarker = GetTileMarker(currentPlayer);
            tileMap[tileNumber] = playerMarker;
            UpdateTileMap(tileMap, rowSize);
            const auto currentTurnData = new CurrentTurn(playerMarker, tileNumber);
            if(HasThreeInARow(*currentTurnData,tileMap)){
                endOfGameMessage = "Player"+to_string(currentPlayer)+ " won!";
                delete currentTurnData;
                break;
            }
            ++currentTurn;
            if(currentTurn > maxSize){
                endOfGameMessage = "Game ended in a draw!";
                delete currentTurnData;
                 break;   
            }
        }
        cout << endOfGameMessage << endl;
        if (BooleanInputCheck('x', "Quit: x, Anything else: play again"))
            break;
    }
    cout << "Thanks for playing Tic tac toe! :) " << endl;
    return 0;
}
