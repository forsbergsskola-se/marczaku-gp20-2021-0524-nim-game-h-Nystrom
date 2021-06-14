#include "TileOptions.h"

    TileOptions::TileOptions(){
        vector<int> opponentsOptions;
        vector<int> ownOptions;
        ownedTiles = 0;
        opponentTiles = 0;
        emptyTileIndex = -1;
    }
    int TileOptions::GetOffensiveTileIndex() const{
        return GetRandomTileIndexFrom(ownOptions);
    }
    int TileOptions::GetDefensiveTileIndex() const{
        return GetRandomTileIndexFrom(opponentsOptions);
    }
    void TileOptions::GetOption(const char tileMarker, const int index){
        switch (tileMarker){
        case 'X': {
            ++ownedTiles;
        }
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
    void TileOptions::GetTwoInARow(const int index, const int moduloValue){
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
    int TileOptions::GetRandomTileIndexFrom(vector<int> emptyTiles){
        if(emptyTiles.empty())
            return -1;
        const int randomNumber = rand() % emptyTiles.size();
        return emptyTiles[randomNumber];
    }
