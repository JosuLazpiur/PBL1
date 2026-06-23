// levelmanager.h
#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "initializer.h" // Incluye los encabezados necesarios

// Declaración de la estructura LevelInfo
typedef struct LevelInfo_S {
    int level;
    int x;
    int y;
    int range;
    int destLevel;
    int destXcoords;
    int destYcoords;
    int walleDirection;
    int IsClosed;
} LevelInfo;

extern LevelInfo levelInfo[];

extern int tpNumber;
extern int currentLevel;

// Prototipo de la función para cambiar de nivel
void changeLevel(int level);

#endif // LEVELMANAGER_H
