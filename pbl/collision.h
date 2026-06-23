// collision.h
#ifndef COLLISION_H
#define COLLISION_H

#include "constants.h" // Include necessary headers

extern int currentLevel;
extern int renderEnter;
extern int tpNumber;
extern int F;
extern int renderBlocked;

int is_collision(float x, float y);
int check_object_collision(float x, float y, int width, int height);
int changeLevelColision(float x, float y);

#endif // COLLISION_H