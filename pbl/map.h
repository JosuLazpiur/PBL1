// map.h
#ifndef MAP_H
#define MAP_H

#include "initializer.h" // Incluye los encabezados necesarios

typedef struct TextureInfo_s {
    int textureNumber;
    const char* imagePath;
    SDL_Texture* texture;
} TextureInfo;


extern TextureInfo gameTextures[];

extern int mapWidth;
extern int mapHeight;

extern int mapData1[];
extern int mapData2[];
extern int mapData3[];

extern int* mapData;

void update_map(float camera_x, float camera_y);

#endif // MAP_H
