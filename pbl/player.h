// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h> // Asegúrate de incluir las bibliotecas necesarias

typedef struct Walle_S {
    float x;
    float y;
    float width;
    float height;
    int currentDirection;
    int currentFrame;
    int totalFrames;
    float frameDuration;
    float elapsedTime;
    int currentQuest;
    int damage;
    int range;
} Walle;

extern Walle walle;

extern int attack;

void renderWalle(struct Walle* walle, SDL_Renderer* renderer);
void updateCharacterAnimation(struct Walle* walle, float deltaTime);
void attack_damage(struct Walle* walle, struct Enemies* enemies);

#endif // PLAYER_H
