#include <SDL.h>
#include <stdio.h>
#include "player.h"
#include "update.h"
#include "constants.h"
#include "collision.h"
#include "inventory.h"
#include "input.h"
#include "notification.h"
#include "map.h"
#include "enemies.h"


float camera_x;
float camera_y;
int last_frame_time = 0;
int lastValidDirection = 1;
int currentLevel = 1;

void update() {
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
        SDL_Delay(time_to_wait);
    }

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0;
    last_frame_time = SDL_GetTicks();

    // Actualizar la animaci�n del personaje
    updateCharacterAnimation(&walle, delta_time);
    int speedMultipier = 5;
    if (attack) {
        speedMultipier = 2;
    }
    float speed = walle.height * speedMultipier * delta_time;

    int collision_up = is_collision(walle.x, walle.y - speed);
    int collision_down = is_collision(walle.x, walle.y + speed);
    int collision_left = is_collision(walle.x - speed, walle.y);
    int collision_right = is_collision(walle.x + speed, walle.y);

    // Verifica colisiones con el agua antes de aplicar el movimiento

    if (UP && !collision_up && !show) {
        walle.y -= speed;
        walle.currentDirection = 1;
        lastValidDirection = walle.currentDirection;
        toxic_value -= 0.5 * delta_time;
    }
    else if (DOWN && !collision_down && !show) {
        walle.y += speed;
        walle.currentDirection = 2;
        lastValidDirection = walle.currentDirection;
        toxic_value -= 0.5 * delta_time;
    }
    else if (LEFT && !collision_left && !show) {
        walle.x -= speed;
        walle.currentDirection = 3;
        lastValidDirection = walle.currentDirection;
        toxic_value -= 0.5 * delta_time;
    }
    else if (RIGHT && !collision_right && !show) {
        walle.x += speed;
        walle.currentDirection = 4;
        lastValidDirection = walle.currentDirection;
        toxic_value -= 0.5 * delta_time;
    }
    else {
        if (walle.currentFrame != 0 && !attack)
        {
            walle.currentFrame = 0;
            walle.elapsedTime = 0.0f;
        }
    }
    // Verifica las colisiones con los bordes del mapa
    if (walle.x < 0) {
        walle.x = 0;
    }
    if (walle.x > (mapWidth * TILE_SIZE - walle.width)) {
        walle.x = mapWidth * TILE_SIZE - walle.width;
    }
    if (walle.y < 0) {
        walle.y = 0;
    }
    if (walle.y > (mapHeight * TILE_SIZE - walle.height)) {
        walle.y = mapHeight * TILE_SIZE - walle.height;
    }
    // Ajusta la posici�n de la c�mara para que siga al personaje
    camera_x = walle.x - (windowWidth / 2);
    camera_y = walle.y - (windowHeight / 2);
    // Aseg�rate de que la c�mara no se desplace fuera de los l�mites del mapawww
    if (camera_x < 0) {
        camera_x = 0;
    }
    if (camera_x > (mapWidth * TILE_SIZE - windowWidth)) {
        camera_x = mapWidth * TILE_SIZE - windowWidth;
    }
    if (camera_y < 0) {
        camera_y = 0;
    }
    if (camera_y > (mapHeight * TILE_SIZE - windowHeight)) {
        camera_y = mapHeight * TILE_SIZE - windowHeight;
    }

    updateEnemies(delta_time);

    use_inventory();
    if (dragged_item_index == -1 && playerInventory.slots[currentItemSlot].itemIndex != 0) {
        use_item(playerInventory.slots[currentItemSlot].itemIndex, currentItemSlot);
    }
}

float calculateDistance(int x1, int y1, int x2, int y2)
{
    float dx = x1 - x2;
    float dy = y1 - y2;
    float distance = sqrt(dx * dx + dy * dy);
    return distance;
}

void updateEnemies(float delta_time)
{
    float distance = calculateDistance(walle.x, walle.y, enemies[0].x, enemies[0].y);

    if (enemies[0].range >= distance && distance >= 70)
    {
        float dx = walle.x - enemies[0].x;
        float dy = walle.y - enemies[0].y;

        // Try moving horizontally
        if (dx > 0)
        {
            if (!is_collision(enemies[0].x + 5, enemies[0].y))
            {
                enemies[0].x += (enemies[0].speed * delta_time);
            }
            else if (!is_collision(enemies[0].x - 5, enemies[0].y))
            {
                enemies[0].x -= (enemies[0].speed * delta_time);
            }
        }
        else
        {
            if (!is_collision(enemies[0].x - 5, enemies[0].y))
            {
                enemies[0].x -= (enemies[0].speed * delta_time);
            }
            else if (!is_collision(enemies[0].x + 5, enemies[0].y))
            {
                enemies[0].x += (enemies[0].speed * delta_time);
            }
        }

        // Try moving vertically
        if (dy > 0)
        {
            if (!is_collision(enemies[0].x, enemies[0].y + 5))
            {
                enemies[0].y += (enemies[0].speed * delta_time);
            }
            else if (!is_collision(enemies[0].x, enemies[0].y - 5))
            {
                enemies[0].y -= (enemies[0].speed * delta_time);
            }
        }
        else
        {
            if (!is_collision(enemies[0].x, enemies[0].y - 5))
            {
                enemies[0].y -= (enemies[0].speed * delta_time);
            }
            else if (!is_collision(enemies[0].x, enemies[0].y + 5))
            {
                enemies[0].y += (enemies[0].speed * delta_time);
            }
        }
    }
}