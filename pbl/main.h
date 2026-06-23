// main.h
#ifndef MAIN_H
#define MAIN_H

#include "constants.h" // Include necessary headers

extern int game_is_running;

int initialize_window();
void loadCharacterAnimations(SDL_Renderer* renderer);
void load_ui_textures(SDL_Renderer* renderer);
void load_object_textures(SDL_Renderer* renderer);
void load_inventory_textures(SDL_Renderer* renderer);
void setup();
void process_input();
void update();
void render();
void destroy_window();

#endif // MAIN_H
