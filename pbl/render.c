#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "render.h"
#include "constants.h"
#include "ui.h"
#include "player.h"
#include "inventory.h"
#include "levelmanager.h"
#include "update.h"
#include "map.h"
#include "collision.h"
#include "quests.h"
#include "enemies.h"
#include "notification.h"

void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) {
    SDL_Rect dest_rect = { x - width / 2, y - height / 2, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
}

void render() {
    SDL_RenderClear(renderer);
    // Ajusta la posici�n de la c�mara antes de renderizar el mapa
    float adjusted_camera_x = round(camera_x);
    float adjusted_camera_y = round(camera_y);
    update_map(adjusted_camera_x / TILE_SIZE, adjusted_camera_y / TILE_SIZE);

    // Renderiza Walle con la nueva funci�n de renderizado
    renderWalle(&walle, renderer);
    renderEnemies(&enemies, renderer);
    render_objects(renderer);
    quest_manager(quests);
    // Renderiza el inventario
    render_inventory();
    if (dragged_item_index != -1) {
        SDL_RenderCopy(renderer, playerInventory.slots[dragged_item_index].texture, NULL, &dragged_item_rect);
    }

    // Renderiza la barra de energ�a (en azul)
    render_toxic_bar();

    // Renderiza la barra de salud (en rojo)
    render_health_bar();
    if (renderEnter) {
        render_texture(renderer, uiItems[4].texture, levelInfo[tpNumber].x - camera_x, levelInfo[tpNumber].y - camera_y - 50, 40, 40);
    }
    if (renderBlocked) {
        show_notification(5);
        if (!show) {
            renderBlocked = FALSE;
        }
    }
    SDL_RenderPresent(renderer);
}
