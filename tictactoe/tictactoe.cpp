using namespace std;
#include <iostream>
#include <string>
#include <limits>


void UpdateUi(string tileMap[]){
    const int rowSize = 3;
    
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
    return tile == "";
}

int main()
{
    string tiles[9];
    UpdateUi(tiles);
}
