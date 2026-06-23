#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "texturemanager.h"
#include "constants.h"
#include "objects.h"
#include "ui.h"
#include "player.h"
#include "enemies.h"
#include "objects.h"
#include "inventory.h"


SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);

SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer) {
    // Construye la ruta completa a la textura en la carpeta "assets"
    char full_path[256];
    snprintf(full_path, sizeof(full_path), "%s%s%s", ASSETS_FOLDER, "/", filename);

    SDL_Surface* surface = IMG_Load(full_path);
    if (!surface) {
        fprintf(stderr, "Error al cargar la imagen %s: %s\n", full_path, IMG_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        fprintf(stderr, "Error al crear la textura desde %s: %s\n", full_path, SDL_GetError());
        return NULL;
    }

    return texture;
}

SDL_Texture* characterTextures[4][11];
SDL_Texture* enemiesTextures[4][11];


void load_inventory_textures(SDL_Renderer* renderer) {
    for (int i = 1; gameItems[i].name != NULL; i++) {
        const char* imagePath = gameItems[i].imagePath;

        if (gameItems[i].texture == NULL) {
            gameItems[i].texture = load_texture(imagePath, renderer);
            if (gameItems[i].texture == NULL) {
                fprintf(stderr, "Error al cargar la textura del objeto %s: %s\n", gameItems[i].name, IMG_GetError());
            }
        }
    }
}

void load_object_textures(SDL_Renderer* renderer) {
    for (int i = 0; gameObjects[i].name != NULL; i++) {
        const char* imagePath = gameObjects[i].imagePath;
        if (gameObjects[i].texture == NULL) {
            gameObjects[i].texture = load_texture(imagePath, renderer);
            if (gameObjects[i].texture == NULL) {
                fprintf(stderr, "Error al cargar la textura del objeto %s: %s\n", gameObjects[i].name, IMG_GetError());
            }
        }
    }
}

void load_ui_textures(SDL_Renderer* renderer) {
    for (int i = 0; uiItems[i].name != NULL; i++) {
        const char* imagePath = uiItems[i].imagePath;
        uiItems[i].texture = load_texture(imagePath, renderer);
    }
}

void loadCharacterAnimations(SDL_Renderer* renderer) {
    const char* directions[] = { "up", "down", "left", "right" };
    const int numFrames = 10;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < numFrames; j++) {
            char imagePath[50];
            if (sprintf_s(imagePath, sizeof(imagePath), "%s%d.png", directions[i], j) < 0) {
                printf("Error constructing image path\n");
                continue;
            }
            characterTextures[i][j] = load_texture(imagePath, renderer);
            if (!characterTextures[i][j]) {
                printf("Error loading texture: %s\n", imagePath);
            }
        }
    }
    walle.totalFrames = numFrames;
    walle.frameDuration = 0.1f;
    walle.currentDirection = 2;
    walle.currentFrame = 0;
}

void loadEnemiesAnimations(SDL_Renderer* renderer)
{
    const char* directions[] = { "up", "down", "left", "right" };
    const int numFrames = 10;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < numFrames; j++)
        {
            char imagePath[50];
            if (sprintf_s(imagePath, sizeof(imagePath), "%s%d.png", directions[i], j) < 0)
            {
                printf("Error constructing image path\n");
                continue;
            }
            enemiesTextures[i][j] = load_texture("slime.png", renderer);
            if (!enemiesTextures[i][j])
            {
                printf("Error loading texture: %s\n", imagePath);
            }
        }
    }
}

void destroy_object_textures() {
    for (int i = 0; gameObjects[i].imagePath != NULL; i++) {
        if (gameObjects[i].texture != NULL) {
            SDL_DestroyTexture(gameObjects[i].texture);
            gameObjects[i].texture = NULL;
        }
    }
}
