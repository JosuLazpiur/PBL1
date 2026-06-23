// objects.h
#ifndef OBJECTS_H
#define OBJECTS_H

#include "initializer.h" 

typedef struct ObjectInfo_S {
    const char* name;
    const char* imagePath;
    int hasCollision;
    SDL_Texture* texture;
    int x;
    int y;
    int objectWidth;
    int objectHeight;
    int canSeeBehind;
    int howMuch;
    int isBehindUser;
} ObjectInfo;

extern ObjectInfo* gameObjects;

void render_objects(SDL_Renderer* renderer);

#endif // OBJECTS_H
