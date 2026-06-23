// render.h
#ifndef RENDER_H
#define RENDER_H

#include <SDL.h> // Asegúrate de incluir las bibliotecas necesarias

void render();
void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height);
void render_inventory();
void render_toxic_bar();
void render_health_bar();

#endif // RENDER_H
