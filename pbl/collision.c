#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "collision.h"
#include "constants.h"
#include "player.h"
#include "levelmanager.h" 
#include "objects.h"
#include "map.h"
#include "inventory.h"
#include "notification.h"

int renderEnter = FALSE;
int renderBlocked = FALSE;
int is_collision(float x, float y)
{
    int collision = 0;

    if (!changeLevelColision(x, y))
    {
        int map_x[] = { (int)(x / TILE_SIZE), (int)((x + walle.width) / TILE_SIZE), (int)(x / TILE_SIZE), (int)((x + walle.width) / TILE_SIZE) };
        int map_y[] = { (int)(y / TILE_SIZE), (int)(y / TILE_SIZE), (int)((y + walle.height) / TILE_SIZE), (int)((y + walle.height) / TILE_SIZE) };

        int i = 0;
        while (i < 4 && !collision)
        {
            int mapValue = mapData[map_y[i] * mapWidth + map_x[i]];

            if (mapValue != 0 && mapValue != 5 && mapValue != 14 && !(mapValue >= 29 && mapValue <= 46) && !(mapValue >= 62 && mapValue <= 81))
            {
                collision = 1;
            }

            i++;
        }

        int objectCollision = check_object_collision(x, y, walle.width, walle.height);

        if (objectCollision)
        {
            collision |= 1;  // Establecer el bit de colisión con objetos
        }
    }

    return collision;
}




int check_object_collision(float x, float y, int width, int height) {
    int collision = FALSE;
    for (int i = 0; gameObjects[i].name != NULL; i++) {
        if (gameObjects[i].hasCollision) {
            float objectTopLeftX = gameObjects[i].x;
            float objectTopLeftY = gameObjects[i].y;
            float objectBottomRightX = objectTopLeftX + gameObjects[i].objectWidth;
            float objectBottomRightY = objectTopLeftY + gameObjects[i].objectHeight;

            float playerEntryLimit = 0;

            if (gameObjects[i].canSeeBehind) {
                playerEntryLimit = objectTopLeftY + gameObjects[i].objectHeight * gameObjects[i].howMuch / 100;
            }

            if (x < objectBottomRightX && x + width > objectTopLeftX &&
                y < objectBottomRightY && y + height > objectTopLeftY) {

                // Hay colisi�n y el personaje no est� detr�s del objeto
                gameObjects[i].isBehindUser = (y <= playerEntryLimit) ? TRUE : FALSE;

                if (!gameObjects[i].isBehindUser) {
                    collision = TRUE;
                    break;
                }
            }
            else {
                // Si el personaje no est� detr�s, restablecer la bandera
                gameObjects[i].isBehindUser = FALSE;
            }
        }
    }

    return collision;
}


int changeLevelColision(float x, float y)
{
    static Uint32 lastCollisionTime = 0;
    int colision = 0;
    Uint32 currentTime = SDL_GetTicks();
    renderEnter = FALSE;
    for (size_t i = 0; i < sizeof(levelInfo[0]); i++)
    {
        if (levelInfo[i].level == currentLevel &&
            sqrt(pow(x - levelInfo[i].x, 2) + pow(y - levelInfo[i].y, 2)) <= levelInfo[i].range)
        {
            // Verifica si ha pasado el tiempo de espera antes de cambiar de nivel
            if (currentTime - lastCollisionTime >= 2000 && !show)
            {
                renderEnter = TRUE;
                tpNumber = i;

                if (F)
                {
                    if (!levelInfo[i].IsClosed) {
                        changeLevel(levelInfo[i].destLevel);
                        walle.x = levelInfo[i].destXcoords;
                        walle.y = levelInfo[i].destYcoords;
                        walle.currentDirection = levelInfo[i].walleDirection;
                        colision = TRUE;
                        lastCollisionTime = currentTime;
                    }
                    else {
                            renderBlocked = TRUE;
                        }
                }
            }
        }
    }

    return colision;
}
