#pragma once
#include "Options.h"

using namespace std;
#include <string>


class Bot{
    
    public:static int PickTile(string tileMap[]){
        //TODO:Implement and refactor:
        int tileIndex = -1;
        auto option = new Options();
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
        for (int i = 0; i < sizeof(tileMap);i++){
            if(tileMap[i][0] == ' ')
                return i;
        }
        
        return 0;
    }

    static bool CanPickMiddleTile(const char middleTile){
    return middleTile == ' ';
    }

    static void FindRowOptions(string* tileMap, Options* option){
        for (int i = 0; i <= sizeof(tileMap); i++){
            option->GetOption(tileMap[i][0],i);
            option->GetTwoInARow(i, 3);
        }
    }

    static void FindColumnOptions(string* tileMap, Options* option){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j <= 6; j+=3){
                const int tileIndex = i+j;
                option->GetOption(tileMap[tileIndex][0],tileIndex);
                option->GetTwoInARow(j,7);
            }    
        }
    }
    static void FindDiagonalOptions(string* tileMap, Options* option){
        for(int i = 0; i <= 2;i+=2){
            for(int j = 2-i; j <= 6+i;j+=2+i){
                option->GetOption(tileMap[j][0],j);
                option->GetTwoInARow(j,7);
            }
        }
    }
};
