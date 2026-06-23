#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "initializer.h"
#include "constants.h"
#include "player.h"


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;
TTF_Font* fontSmall = NULL;

int windowWidth = WINDOW_WIDTH;
int windowHeight = WINDOW_HEIGHT;

int initialize_window() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "SDL error.\n");
        return FALSE;
    }

    window = SDL_CreateWindow("Eco heroes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, NULL);
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return FALSE;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        fprintf(stderr, "Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return FALSE;
    }

    if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) {
        fprintf(stderr, "Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return FALSE;
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
        return FALSE;
    }

    font = TTF_OpenFont("font/pixelart.ttf", 24);
    if (!font) {
        fprintf(stderr, "Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_Quit();
        return FALSE;
    }
    fontSmall = TTF_OpenFont("font/pixelart.ttf", 20);
    if (!fontSmall)
    {
        fprintf(stderr, "Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_Quit();
        return FALSE;
    }
    return TRUE;
}

void toggle_fullscreen() {
    if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
        SDL_SetWindowFullscreen(window, 0);
        SDL_SetWindowSize(window, WINDOW_WIDTH, WINDOW_HEIGHT);
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    }
    else {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    }
}

void destroy_window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void setup() {
    walle.width = 50;
    walle.height = walle.width + 20;
    walle.x = 2448;
    walle.y = 1534;
    walle.currentQuest = 2;
    toxic_value = 100;
    health_value = 80;
    changeLevel(3);
    walle.range = 100;
    walle.damage = 20;
    add_item(4, 1);
    add_item(5, 1);
    add_item(6, 1);
    add_item(7, 1);
}
