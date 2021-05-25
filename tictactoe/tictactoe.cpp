using namespace std;
#include <iostream>
#include <string>
#include <limits>

void InstantiateTileMap(string tileMap[]){
    for (int i = 0; i <= sizeof(tileMap);i++){
        tileMap[i] = " ";
    }
}
void UpdateUi(string tileMap[], int rowSize){
    for (int i = 0; i <=  sizeof(tileMap);i++){
        cout << " | " + tileMap[i] << flush;
        const int tempNumber = i + 1;
        if(tempNumber % rowSize == 0){
            cout << " | " << endl;
            cout << "---------------" << endl;
        }
            
    }
}
int PickTile(int currentPlayer){
    cout << "Player"+ to_string(currentPlayer) + "'s turn to pick tile: " << endl;
    return 5;
}

bool IsTileEmpty(string tile){
    return tile == " ";
}

int main()
{
    const int rowSize = 3;
    string tiles[9];
    int currentPlayer = 0;
    InstantiateTileMap(tiles);
    UpdateUi(tiles, rowSize);

    
    int tileNumber = PickTile(currentPlayer);
    
    if(currentPlayer == 1)
    tiles[tileNumber] = "O";
    else
    tiles[tileNumber] = "X";
    UpdateUi(tiles, rowSize);
}
