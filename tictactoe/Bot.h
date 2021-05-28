#pragma once
#include "Options.h"
using namespace std;
#include <string>


class Bot{
    public:
    static int PickTile(string tileMap[]);

    private:
    static bool CanPickMiddleTile(char middleTile);
    static void FindRowOptions(string* tileMap, Options* option);
    static void FindColumnOptions(string* tileMap, Options* option);
    static void FindDiagonalOptions(string* tileMap, Options* option);
    static int GetRandomEvenEmptyTileIndex(string* tileMap);
    static int GetFirstEmptyTileIndex(string* tileMap);
};
