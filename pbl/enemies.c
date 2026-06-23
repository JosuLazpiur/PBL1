#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "enemies.h"
#include "constants.h"
#include "update.h"
#include "texturemanager.h"

void renderEnemies(Enemies* enemies, SDL_Renderer* renderer) {
    for (int i = 0; i < 1; i++) {
        if (enemies[i].level == currentLevel && enemies[i].health > 0) {
            SDL_Rect enemyRect = {
                round(enemies[i].x - camera_x),
                round(enemies[i].y - camera_y),
                enemies[i].width,
                enemies[i].height
            };
            SDL_RenderCopy(renderer, enemiesTextures[enemies[i].currentDirection - 1][enemies[i].currentFrame], NULL, &enemyRect);
            renderEnemiesHealthBar(enemies, renderer);
        }
    }
}


Enemies enemies[] = {
    {1200, 400, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 2, 100},
};

void renderEnemiesHealthBar(Enemies* enemies, SDL_Renderer* renderer)
{
    for (int i = 0; i < 1; i++)
    {
        if (enemies[i].level == currentLevel && 100 > enemies[i].health > 0)
        {
            int bar_x = enemies[i].x - camera_x - 10;
            int bar_y = enemies[i].y - camera_y - 30;
            int bar_width = 70;
            int bar_height = 10;

            // Dibuja el fondo de la barra (puedes ajustar el color)
            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
            SDL_RenderFillRect(renderer, &bar_rect);

            // Calcula la longitud de la barra seg�n un valor (0 a 100)
            int bar_fill_width = (int)((enemies[i].health / 100.0) * (bar_width));

            // Dibuja la parte llena de la barra (puedes ajustar el color)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
            SDL_RenderFillRect(renderer, &bar_fill_rect);
        }
    }
}