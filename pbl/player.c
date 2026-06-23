#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "player.h"
#include "enemies.h"
#include "constants.h"
#include "update.h"
#include "texturemanager.h"

int attack;

Walle walle;

void renderWalle(Walle* walle, SDL_Renderer* renderer)
{
    SDL_Rect walle_rect = {
        round(walle->x - camera_x),
        round(walle->y - camera_y),
        walle->width,
        walle->height
    };
    SDL_RenderCopy(renderer, characterTextures[walle->currentDirection - 1][walle->currentFrame], NULL, &walle_rect);
}

void updateCharacterAnimation(Walle* walle, float deltaTime)
{
    if (walle->currentDirection != 0)
    {
        walle->elapsedTime += deltaTime;
        if (attack && walle->elapsedTime >= walle->frameDuration)
        {
            if (walle->currentFrame == 7)
            {
                attack_damage(walle, enemies);
            }
            if (walle->currentFrame >= 7 && walle->currentFrame < 10)
            {
                walle->currentFrame += 1;
                walle->elapsedTime = 0.0f;
            }
            else
            {
                walle->currentFrame = 7;
                walle->elapsedTime = 0.0f;
            }

            if (walle->currentFrame > 9)
            {
                attack = FALSE;
                walle->currentFrame = 0;
            }
        }
        else
        {
            if (walle->elapsedTime >= walle->frameDuration)
            {
                if (walle->currentFrame < 6)
                {
                    walle->currentFrame += 1;
                    walle->elapsedTime = 0.0f;
                }
                else
                {
                    walle->currentFrame = 0;
                    walle->elapsedTime = 0.0f;
                }
            }
        }
    }
}

void attack_damage(Walle* walle, Enemies* enemies)
{
    for (int i = 0; i < 1; i++)
    {
        if (enemies[i].level == currentLevel)
        {
            if (calculateDistance(walle->x, walle->y, enemies[i].x, enemies[i].y) <= walle->range)
            {
                enemies[i].health -= walle->damage;
                switch (walle->currentDirection)
                {
                case 1: enemies[i].y -= 100;
                case 2: enemies[i].y += 100;
                case 3: enemies[i].x -= 100;
                case 4: enemies[i].x += 100;
                }
            }
        }
    }
}
