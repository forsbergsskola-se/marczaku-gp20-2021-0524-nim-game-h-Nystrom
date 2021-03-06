#pragma once
using namespace std;
#include <vector>

class TileOptions{
    vector<int> opponentsOptions;
    vector<int> ownOptions;
    int ownedTiles;
    int opponentTiles;
    int emptyTileIndex;

    public:
        TileOptions();
        int GetOffensiveTileIndex() const;
        int GetDefensiveTileIndex() const;
        void GetOption(char tileMarker,int index);
        void GetTwoInARow(int index, int moduloValue);
    private:
        static int GetRandomTileIndexFrom(vector<int> emptyTiles);
};
