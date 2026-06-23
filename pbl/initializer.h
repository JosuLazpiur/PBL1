// initializer.h
#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "constants.h" // Include necessary headers
#include "SDL_ttf.h" // Include necessary headers

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font* font;
extern TTF_Font* fontSmall;

extern int windowWidth;
extern int windowHeight;

extern float toxic_value;
extern float health_value;

int initialize_window();
void toggle_fullscreen();
void destroy_window();
void setup();

#endif // INITIALIZER_H
