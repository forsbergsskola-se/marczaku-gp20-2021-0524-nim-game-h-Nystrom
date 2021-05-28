#pragma once
#include "TileOptions.h"
using namespace std;
#include <string>


class Bot{
    public:
    static int PickTile(string tileMap[]);
    private:
    static bool CanPickMiddleTile(char middleTile);
    static void FindRowOptions(string* tileMap, TileOptions* option);
    static void FindColumnOptions(string* tileMap, TileOptions* option);
    static void FindDiagonalOptions(string* tileMap, TileOptions* option);
    static int GetRandomEmptyCornerTileIndex(string* tileMap);
    static int GetFirstEmptyTileIndex(string* tileMap);
};
