#pragma once
#include <cstdlib>

class Options{
    int OpponentsTwoInARowEmptyIndex[6]{-1,-1,-1,-1,-1,-1};
    int OwnTwoInARowEmptyIndex[6]{-1,-1,-1,-1,-1,-1};
    int ownedTiles = 0;
    int opponentTiles = 0;
    int emptyTileIndex = -1;
    public:int GetOffensiveTileIndex(){
        return GetRandomTileIndexFrom(OwnTwoInARowEmptyIndex);
    }
    public:int GetDefensiveTileIndex(){
        return GetRandomTileIndexFrom(OpponentsTwoInARowEmptyIndex);
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
                    AddToArray(OwnTwoInARowEmptyIndex, emptyTileIndex);
                else if(opponentTiles == 2)
                    AddToArray(OpponentsTwoInARowEmptyIndex, emptyTileIndex);
            }
            ownedTiles = 0;
            opponentTiles = 0;
            emptyTileIndex = -1;
        }
    }

    static void AddToArray(int emptyTiles[6], const int tileIndex){
        for (int i = 0; i < sizeof(emptyTiles);i++){
            if(emptyTiles[i] == -1)
                emptyTiles[i] = tileIndex;
        }
    }
    static int GetRandomTileIndexFrom(int emptyTiles[6]){
        const int maxLength = 5;
        for(int i = 0; i <= maxLength;i++){
            const int randomNumber = rand() % maxLength;
            if(emptyTiles[randomNumber] != -1)
                return emptyTiles[randomNumber];
        }
        return -1;
    }
};
