#pragma once
#include <cstdlib>

class Options{
    vector<int>opponentsOptions;
    vector<int> ownOptions;
    int ownedTiles = 0;
    int opponentTiles = 0;
    int emptyTileIndex = -1;
    public:int GetOffensiveTileIndex(){
        return GetRandomTileIndexFrom(ownOptions);
    }
    public:int GetDefensiveTileIndex(){
        return GetRandomTileIndexFrom(opponentsOptions);
    }
    void GetOption(const char tileMarker, const int index){
        switch (tileMarker){
        case 'X':
            ++ownedTiles;
            break;
        case 'O':
            ++opponentTiles;
            break;
        case ' ':
            emptyTileIndex = index;
            break;
        default:
            emptyTileIndex = index;
            break;
        }
    }
    void GetTwoInARow(const int index, const int moduloValue){
        if((index+1) % moduloValue == 0){
            if(emptyTileIndex != -1){
                if(ownedTiles == 2)
                    ownOptions.push_back(emptyTileIndex);
                else if(opponentTiles == 2)
                    opponentsOptions.push_back(emptyTileIndex);
            }
            ownedTiles = 0;
            opponentTiles = 0;
            emptyTileIndex = -1;
        }
    }
    static int GetRandomTileIndexFrom(vector<int> emptyTiles){
        if(emptyTiles.empty())
            return -1;
            const int randomNumber = rand() % emptyTiles.size();
            return emptyTiles[randomNumber];
    }
};
