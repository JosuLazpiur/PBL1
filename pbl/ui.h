// ui.h
#ifndef UI_H
#define UI_H

#include <SDL.h>

extern float toxic_value;
extern float health_value;

typedef struct UiItem_S {
    const char* name;
    const char* imagePath;
    SDL_Texture* texture;
} UiItem;

extern UiItem uiItems[];

void render_toxic_bar();
void render_health_bar();

#endif // UI_H
