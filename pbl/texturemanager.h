// texturemanager.h
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>  // Asegúrate de incluir la biblioteca SDL_image

extern SDL_Texture* characterTextures[4][11];
extern SDL_Texture* enemiesTextures[4][11];

SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
void load_inventory_textures(SDL_Renderer* renderer);
void load_object_textures(SDL_Renderer* renderer);
void load_ui_textures(SDL_Renderer* renderer);
void loadCharacterAnimations(SDL_Renderer* renderer);
void loadEnemiesAnimations(SDL_Renderer* renderer);
void destroy_object_textures();

#endif // TEXTUREMANAGER_H
