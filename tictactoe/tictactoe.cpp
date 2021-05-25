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

bool HasThreeInARow(const int currentPlayer,string tileMap[]){
    string playerMarker = GetTileMarker(currentPlayer);
    for (int i = sizeof(tileMap); i >= 0; i--){
        int inRowCounter = 0;
        if(tileMap[i] != playerMarker)
            continue;
        if(i % 3 == 0){
            for (int horizontalIndex = i-1; horizontalIndex >= 0; horizontalIndex--){
            if(tileMap[horizontalIndex] != playerMarker)
                break;
            }
            inRowCounter++;
            if(inRowCounter == 2)
                return true;
        }
        
        //-1, -2
        //-3*1, -3*2
        //-4*1, -4*2
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

            // if(HasThreeInARow(currentPlayer,tileMap)){
            //     break;
            // }
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
