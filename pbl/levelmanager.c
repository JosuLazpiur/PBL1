#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "levelmanager.h"
#include "constants.h"
#include "objects.h"
#include "map.h"

int tpNumber;
int currentLevel;

extern ObjectInfo gameObjects1[];
extern ObjectInfo gameObjects2[];
extern ObjectInfo gameObjects3[];

LevelInfo levelInfo[] = {

    //TP BUNKER

    {1, 1007, 389, 50, 1, 2450, 386, 1, FALSE},
    {1, 2450, 389, 50, 1, 1007, 389, 1, FALSE},

    {1, 3167, 1226, 50, 1, 4107, 860, 1, FALSE},
    {1, 4107, 860,  50, 1, 3167, 1226, 1, FALSE},

    {1, 2677, 976, 50, 1, 4133, 3503, 1, FALSE},
    {1, 4133, 3503, 50, 1, 2667, 976, 1, FALSE},

    {1, 2666, 1463, 50, 1, 4718, 2423, 1, FALSE},
    {1, 4718, 2423, 50, 1, 2666, 1463, 1, FALSE},

    {1, 2912, 1700, 50, 1, 1236, 2898, 1, FALSE},
    {1, 1260, 2898, 50, 1, 2912, 1700, 1, FALSE},

    {1, 535, 2898, 50, 1, 754, 2180, 1, TRUE},
    {1, 780, 2175, 50, 1, 510, 2898, 1, FALSE},

    {1, 660, 1461, 50, 1, 756, 749, 1, FALSE},
    {1, 780, 749, 50, 1, 633, 1461, 1, TRUE},

    {1, 876, 3369, 100, 2, 277, 611, 1, TRUE},

    {2, 1950, 550, 100, 3, 28, 375, 1, TRUE},
    {3, 28, 375, 100, 2, 1950, 550, 1, FALSE},
};

void changeLevel(int level)
{
    destroy_object_textures(renderer);
    currentLevel = level;
    switch (level)
    {
    case 1:
        mapData = mapData1;
        mapWidth = 45;
        mapHeight = 45;
        gameObjects = gameObjects1;
        load_object_textures(renderer);
        break;
    case 2:
        mapData = mapData2;
        mapWidth = 17;
        mapHeight = 10;
        gameObjects = gameObjects2;
        load_object_textures(renderer);

        break;
    case 3:
        mapData = mapData3;
        mapWidth = 30;
        mapHeight = 30;
        gameObjects = gameObjects3;
        load_object_textures(renderer);
        break;
    }
}