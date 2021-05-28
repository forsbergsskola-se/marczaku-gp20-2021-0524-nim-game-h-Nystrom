#include "Bot.h"
 
    int Bot::PickTile(string tileMap[]){
        int tileIndex = -1;
        const auto option = new Options();
        FindRowOptions(tileMap, option);
        FindColumnOptions(tileMap, option);
        FindDiagonalOptions(tileMap, option);
        
        tileIndex = option->GetOffensiveTileIndex();
        if(tileIndex != -1)
            return tileIndex;
        
        tileIndex = option->GetDefensiveTileIndex();
        if(tileIndex != -1)
            return tileIndex;
        
        if(CanPickMiddleTile(tileMap[4][0])){
            return 4;
        }
        const int emptyTileIndex = GetRandomEmptyCornerTileIndex(tileMap);
        if(emptyTileIndex != -1)
            return emptyTileIndex;
        return GetFirstEmptyTileIndex(tileMap);
    }
    bool Bot::CanPickMiddleTile(const char middleTile){
        return middleTile == ' ';
    }

    void Bot::FindRowOptions(string* tileMap, Options* option){
        for (int i = 0; i <= sizeof(tileMap); i++){
            option->GetOption(tileMap[i][0],i);
            option->GetTwoInARow(i, 3);
        }
    }
    void Bot::FindColumnOptions(string* tileMap, Options* option){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j <= 6; j+=3){
                const int tileIndex = i+j;
                option->GetOption(tileMap[tileIndex][0],tileIndex);
                option->GetTwoInARow(j,7);
            }    
        }
    }
    void Bot::FindDiagonalOptions(string* tileMap, Options* option){
        for(int i = 0; i <= 2;i+=2){
            for(int j = 0+i; j <= 8-i;j+=4-i){
                option->GetOption(tileMap[j][0],j);
                option->GetTwoInARow(j, 9-i);
            }
        }
    }
    int Bot::GetRandomEmptyCornerTileIndex(string* tileMap){
        auto tileMapCopy = new vector<int>();
        
        for (int i = 0; i < sizeof(tileMap);i++){
            if(tileMap[i][0] == ' ' && i % 2 == 0)
                tileMapCopy->push_back(i);
        }
        if(tileMapCopy->size() == 0)
            return -1;
        const int randomNumber = rand() % tileMapCopy->size();
        return tileMapCopy->at(randomNumber);
    }
    int Bot::GetFirstEmptyTileIndex(string* tileMap){
        for (int i = 0; i < sizeof(tileMap);i++){
            if(tileMap[i][0] == ' ')
                return i;
        }
        return -1;
    }
