using namespace std;
#include <iostream>
#include <string>
#include <limits>

void InstantiateTileMap(string tileMap[]){
    for (int i = 0; i <= sizeof(tileMap);i++){
        tileMap[i] = " ";
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
bool IsTileEmpty(const string tile){
    return tile == " ";
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
            else if (!IsTileEmpty(tileMap[playerInput-indexAdjuster]))
                errorMessage = "Needs to be an empty tile!";
            else
                return --playerInput;
        }else{
            errorMessage = "Needs to be a number between 1 and " + to_string(maxIndex) + "!";
        }
        cout << errorMessage << endl;
    }
}
int BotPickTile(const int currentPlayer){
    //TODO:Implement
    //1: own 2 in a row tiles...
    //2: opponents 2 in a row tiles...
    //3: middle tile...
    //4: diagonal tiles (X%2)...
    //5: Random of what is left...
    
    cout << "Player"+ to_string(currentPlayer) + "'s turn to pick tile: " << endl;
    return 5;
}

int NextPlayer(const int currentPlayer){
    return currentPlayer == 1 ? 2 : 1;
}
string GetTileMarker(const int currentPlayer){
    return currentPlayer == 1 ? "O" : "X";
}

bool BooleanInputCheck(const string valueCheck, const string message) {
    string inputValue;
    cout << message << endl;
    getline(cin, inputValue);
    return inputValue == valueCheck;
}
class CurrentTurnData{
public:string marker;
public:int newTileIndex;
    CurrentTurnData(const string playerMarker, const int playerTileNumber){
        this->marker = playerMarker;
        this-> newTileIndex = playerTileNumber;
    }
};
bool DiagonalCheck(const CurrentTurnData currentTurn,string tileMap[]){
    const int middleTileValue = 4;
    if(tileMap[middleTileValue] == currentTurn.marker && currentTurn.newTileIndex % 2 == 0){
        for (int i = 6; i <= 8; i++){
            if(tileMap[i] == currentTurn.marker && tileMap[i%middleTileValue] == currentTurn.marker){
                return true;
            }
            ++i;
        }
    }
    return false;
}
bool RowCheck(const CurrentTurnData currentTurnData,string tileMap[]){
    const int columnLength = 3;
    for (int i = 0; i < columnLength; i++){
        const int temp = currentTurnData.newTileIndex % columnLength + i * columnLength;
        if(tileMap[temp] != currentTurnData.marker)
            break;
        if(i==2)
            return true;
    }
    return false;
}

bool ColumnCheck(const CurrentTurnData playerTurnData,string tileMap[]){
    const int rowLength = 3;
    for (int i = 0; i < rowLength; i++){
        const int temp = playerTurnData.newTileIndex - playerTurnData.newTileIndex % rowLength + i;
        if(tileMap[temp] != playerTurnData.marker)
            break;
        if(i==2)
            return true;
    }
    return false;
}

bool HasThreeInARow(const CurrentTurnData currentTurnData,string tileMap[]){
    if(DiagonalCheck(currentTurnData, tileMap))
        return true;
    if(RowCheck(currentTurnData, tileMap))
        return true;
    if(ColumnCheck(currentTurnData, tileMap))
        return true;   
    return false;
}
    
int main(){
    const int maxSize = 9;
    string tileMap[maxSize];
    
    while (true) {
        const int rowSize = 3;
        const bool bot = BooleanInputCheck("b", "vs bot: b, pvp: other");
        int currentPlayer = 0;
        int tileNumber;
        int currentTurn = 1;
        string endOfGameMessage;
        InstantiateTileMap(tileMap);    
        UpdateTileMap(tileMap, rowSize);
        
        while (true){
            currentPlayer = NextPlayer(currentPlayer);
            if(bot && currentPlayer == 2){
                tileNumber = BotPickTile(currentPlayer);
            }
            else{
                tileNumber = PickTile(currentPlayer, tileMap);
            }
            tileMap[tileNumber] = GetTileMarker(currentPlayer);
            UpdateTileMap(tileMap, rowSize);
            const auto currentTurnData = new CurrentTurnData(GetTileMarker(currentPlayer),tileNumber);
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
        if (BooleanInputCheck("x", "Quit: x, Anything else: play again"))
            break;
    }
    cout << "Thanks for playing Tic tac toe! :) " << endl;
    return 0;
}
