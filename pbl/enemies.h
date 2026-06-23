#ifndef ENEMIES_H
#define ENEMIES_H

#include <SDL.h>

typedef struct Enemies_S {
    float x;
    float y;
    float width;
    float height;
    int currentDirection;
    int currentFrame;
    int totalFrames;
    float frameDuration;
    float elapsedTime;
    int range;
    int damage;
    float speed; 
    int level;
    int health;
} Enemies;

extern Enemies enemies[];
void renderEnemiesHealthBar(Enemies* enemies, SDL_Renderer* renderer);
extern void renderEnemies(Enemies* enemies, SDL_Renderer* renderer);

#endif // ENEMIES_H
