using namespace std;
#include <iostream>
#include <string>
#include <limits>

void InstantiateTileMap(string tileMap[]){
    for (int i = 0; i <= sizeof(tileMap);i++){
        tileMap[i] = " ";
    }
}
void UpdateTileMap(string tileMap[], int rowSize){
    for (int i = 0; i <=  sizeof(tileMap);i++){
        cout << " | " + tileMap[i] << flush;
        const int tempNumber = i + 1;
        if(tempNumber % rowSize == 0){
            cout << " | " << endl;
            cout << "---------------" << endl;
        }
            
    }
}
bool IsTileEmpty(string tile){
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
int BotPickTile(int currentPlayer){
    cout << "Player"+ to_string(currentPlayer) + "'s turn to pick tile: " << endl;
    return 5;
}

int NextPlayer(const int currentPlayer){
    return currentPlayer == 1 ? 2 : 1;
}
string GetTileMarker(const int currentPlayer){
    return currentPlayer == 1 ? "O" : "X";
}

bool BooleanInputCheck(string valueCheck, string message) {
    string inputValue;
    cout << message << endl;
    getline(cin, inputValue);
    return inputValue == valueCheck;
}

bool HasThreeInARow(const int currentPlayer,const int newTileNumber,string tileMap[]){
    const string playerMarker = GetTileMarker(currentPlayer);

    //TODO: Check diagonals
    if(tileMap[4] == playerMarker && newTileNumber % 2 == 0){
        //Middle is theirs!
        //Check 0 and 2
        //Check 6 and 8
    }
    //TODO: VerticalCheck:
    for (int i = 0; i < 3; i++){
        const int temp = newTileNumber % 3 + i * 3;
        if(tileMap[temp] != playerMarker)
            break;
        if(i==2)
            return true;
    }
    //TODO: HorizontalCheck:
    for (int i = 0; i < 3; i++){
        const int temp = newTileNumber - newTileNumber % 3 + i;
        if(tileMap[temp] != playerMarker)
            break;
        if(i==2)
            return true;
    }
    
 return false;   
}

int main(){
    const int rowSize = 3;
    const int maxSize = 9;
    string tileMap[maxSize];
    
    while (true) {
        bool bot = BooleanInputCheck("b", "vs bot: b, pvp: other");
        int currentPlayer = 0;
        int tileNumber = 0;
        int currentTurn = 1;
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

            if(HasThreeInARow(currentPlayer, tileNumber,tileMap)){
                break;
            }
            ++currentTurn;
            if(currentTurn > maxSize){
                 break;   
            }
        }
        cout << "End of game message" << endl;
        if (BooleanInputCheck("x", "Quit: x"))
            break;
    }
    cout << "Thanks for playing Tic tac toe! :) " << endl;
    return 0;
}
