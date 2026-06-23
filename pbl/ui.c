#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "ui.h"
#include "constants.h"
#include "initializer.h"


float toxic_value;
float health_value;

UiItem uiItems[] = {
    {"ebutton", "e_button.png", NULL},
    {"toxic", "toxic.png", NULL},
    {"heart", "heart.png", NULL},
    {"infobox", "infobox.png", NULL},
    {"fbutton", "f_button.png", NULL},
    {"marco", "marco.png", NULL},
    {"shadow", "shadow.png", NULL},
    {"questborder", "questborder.png", NULL},
    {NULL, NULL, NULL},
};

void render_toxic_bar() {
    // Calcula la posici�n y dimensiones de la barra
    int bar_x = windowWidth - 280;
    int bar_y = windowHeight - 80;
    int bar_width = 210;
    int bar_height = 33;

    // Dibuja el fondo de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_rect);

    // Calcula la longitud de la barra seg�n un valor (0 a 100)
    int bar_fill_width = (int)((toxic_value / 100.0) * (bar_width - 2)); // Resta 2 para el margen

    if (toxic_value > 100) {
        toxic_value = 100;
    }
    if (toxic_value < 0) {
        toxic_value = 0;
    }

    // Dibuja la parte llena de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 62, 162, 20, 255);
    SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_fill_rect);
    render_texture(renderer, uiItems[1].texture, bar_x + 72, bar_y + 20, 350, 120);
}

void render_health_bar() {
    // Calcula la posici�n y dimensiones de la barra
    int bar_x = 128;
    int bar_y = windowHeight - 80;
    int bar_width = 210;
    int bar_height = 33;

    // Dibuja el fondo de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_rect);

    // Calcula la longitud de la barra seg�n un valor (0 a 100)
    int bar_fill_width = (int)((health_value / 100.0) * (bar_width - 2)); // Resta 2 para el margen

    if (health_value > 100) {
        health_value = 100;
    }
    if (health_value < 0) {
        health_value = 0;
    }

    // Dibuja la parte llena de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 187, 48, 71, 255);
    SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_fill_rect);
    render_texture(renderer, uiItems[2].texture, 200, bar_y + 20, 350, 120);
}

