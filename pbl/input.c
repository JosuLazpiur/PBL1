#include <SDL.h>
#include <stdio.h>

#include "input.h"
#include "main.h"
#include "constants.h"


int UP = FALSE;
int DOWN = FALSE;
int LEFT = FALSE;
int RIGHT = FALSE;
int LETRAE = FALSE;
int NUM1 = FALSE;
int NUM2 = FALSE;
int NUM3 = FALSE;
int NUM4 = FALSE;
int NUM5 = FALSE;
int TAB = FALSE;
int F = FALSE;
int SPACE = FALSE;


void process_input() {
    SDL_Event event;
    //comprobar si hay eventos pendientes para mejorar rendimiento
    while (SDL_PollEvent(&event)) {
        handle_drag_and_drop(&event);

        switch (event.type) {
        case SDL_QUIT:
            game_is_running = FALSE;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                game_is_running = FALSE;
                break;
            case SDLK_w:
                UP = TRUE;
                break;
            case SDLK_s:
                DOWN = TRUE;
                break;
            case SDLK_a:
                LEFT = TRUE;
                break;
            case SDLK_d:
                RIGHT = TRUE;
                break;
            case SDLK_e:
                LETRAE = TRUE;
                break;
            case SDLK_1:
                NUM1 = TRUE;
                break;
            case SDLK_2:
                NUM2 = TRUE;
                break;
            case SDLK_3:
                NUM3 = TRUE;
                break;
            case SDLK_4:
                NUM4 = TRUE;
                break;
            case SDLK_5:
                NUM5 = TRUE;
                break;
            case SDLK_TAB:
                TAB = TRUE;
                break;
            case SDLK_f:
                F = TRUE;
                break;
            case SDLK_SPACE:
                SPACE = TRUE;
                break;
            case SDLK_F11:
                toggle_fullscreen();
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
            case SDLK_w:
                UP = FALSE;
                break;
            case SDLK_s:
                DOWN = FALSE;
                break;
            case SDLK_a:
                LEFT = FALSE;
                break;
            case SDLK_d:
                RIGHT = FALSE;
                break;
            case SDLK_e:
                LETRAE = FALSE;
                break;
            case SDLK_1:
                NUM1 = FALSE;
                break;
            case SDLK_2:
                NUM2 = FALSE;
                break;
            case SDLK_3:
                NUM3 = FALSE;
                break;
            case SDLK_4:
                NUM4 = FALSE;
                break;
            case SDLK_5:
                NUM5 = FALSE;
                break;
            case SDLK_f:
                F = FALSE;
                break;
            case SDLK_SPACE:
                SPACE = FALSE;
                break;
            case SDLK_TAB:
                TAB = FALSE;
                break;
            }
            break;
        }
    }
}