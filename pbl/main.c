#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "constants.h"
#include "initializer.h"
#include "map.h"
#include "render.h"
#include "update.h"
#include "input.h"
#include "texturemanager.h"
#include "ui.h"
#include "collision.h"
#include "levelmanager.h"
#include "inventory.h"
#include "player.h"



int game_is_running = FALSE;


int main(int argc, char* argv[]) {
    game_is_running = initialize_window();
    loadCharacterAnimations(renderer);
    loadEnemiesAnimations(renderer);
    load_ui_textures(renderer);
    load_object_textures(renderer);
    load_inventory_textures(renderer);
    setup();
    while (game_is_running) {
        process_input();
        update();
        render();
        //printf("%f %f\n", walle.x, walle.y);
        //printf("%d", levelInfo);
    }
    destroy_window();
    return 0;
}