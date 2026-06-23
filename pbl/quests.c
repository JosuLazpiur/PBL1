#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

#include "constants.h"
#include "quests.h"
#include "player.h"
#include "enemies.h"
#include "update.h"
#include "render.h"
#include "notification.h"
#include "inventory.h"
#include "input.h"
#include "objects.h"
#include "ui.h"
#include "texturemanager.h"
#include "levelmanager.h"

int bunkerShadow = FALSE;

Quests quests[] = {
    { "BUNKERETIK IRTEN", 0, 0 },
    { "ZER DA HAU?", 1, 0},
    { "TOROIDE", 2, 0 },
    { NULL, 3, 0 },
    { NULL, 4, 0 },
};

void quest_manager(Quests quests[])
{
    switch (walle.currentQuest)
    {
    case 0:
    {
        quest0();
        break;
    }
    case 1:
    {
        quest1();
        break;
    }
    case 2:
    {
        quest2();
        break;
    }
    }
    renderMissionProgress(quests);
}

void add_quest_progress(Quests quests[], int currentQuest, int progressQuantity)
{
    quests[currentQuest].progress += progressQuantity;
}

void renderMissionProgress(Quests quests[])
{
    int currentQuest = walle.currentQuest;
    int currentQuestProgressValue = quests[walle.currentQuest].progress;
    render_mission_text(quests, currentQuest);
    // Calcula la posici�n y dimensiones de la barra
    int bar_width = 235;
    int bar_height = 15;
    int bar_x = windowWidth - bar_width - 20;
    int bar_y = 80;

    // Dibuja el fondo de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_rect);

    // Calcula la longitud de la barra seg�n un valor (0 a 100)
    int bar_fill_width = (int)((currentQuestProgressValue / 100.0) * (bar_width - 2)); // Resta 2 para el margen

    if (currentQuestProgressValue > 100)
    {
        currentQuestProgressValue = 100;
    }
    if (currentQuestProgressValue < 0)
    {
        currentQuestProgressValue = 0;
    }

    // Dibuja la parte llena de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_fill_rect);
    render_texture(renderer, uiItems[7].texture, bar_x + bar_width / 2, bar_y + bar_height / 2, bar_width, bar_height);
}

void render_mission_text(Quests quests[], int currentMissionIndex)
{
    SDL_Color color = { 255, 255, 255 };
    char* text = quests[currentMissionIndex].questName;

    SDL_Surface* surface = TTF_RenderText_Solid(fontSmall, text, color);
    if (!surface)
    {
        fprintf(stderr, "Error al renderizar el texto: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        fprintf(stderr, "Error al crear la textura: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect destRect;
    destRect.w = surface->w;
    destRect.h = surface->h;
    destRect.x = windowWidth - destRect.w - 20;
    destRect.y = 50;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void quest0()
{
    if (bunkerShadow)
    {
        render_texture(renderer, uiItems[6].texture, walle.x - camera_x + 35, walle.y - camera_y + 50, 1920 * 2, 1080 * 2);
    }
    if (quests[0].progress == 0)
    {
        show_notification(0);
        if (!show)
        {
            add_quest_progress(quests, 0, 10);
        }
    }
    if (quests[0].progress == 10)
    {
        render_texture(renderer, gameItems[2].texture, 4630 - camera_x, 630 - camera_y - 50, 40, 40);
        if (calculateDistance(walle.x, walle.y, 4600, 660) <= 30)
        {
            render_texture(renderer, uiItems[4].texture, 4630 - camera_x, 660 - camera_y - 50, 40, 40);
            if (F)
            {
                add_quest_progress(quests, 0, 15);
                add_item(2, 1);
                levelInfo[10].IsClosed = FALSE;
                levelInfo[13].IsClosed = FALSE;
            }

        }
    }

    if (quests[0].progress == 25)
    {
        show_notification(3);
        if (!show)
        {
            add_quest_progress(quests, 0, 25);
        }
    }
    if (quests[0].progress == 50 && calculateDistance(walle.x, walle.y, 350, 1690) <= 30)
    {
        render_texture(renderer, uiItems[4].texture, 350 - camera_x, 1690 - camera_y - 50, 40, 40);
        if (F)
        {
            bunkerShadow = TRUE;
            add_quest_progress(quests, 0, 25);
        }
    }
    if (quests[0].progress == 75)
    {
        show_notification(6);
        if (!show)
        {
            add_quest_progress(quests, 0, 10);
        }
    }
    if (quests[0].progress == 85)
    {
        if (levelInfo[14].IsClosed)
            levelInfo[14].IsClosed = FALSE;
    }
    if (currentLevel == 2)
    {
        walle.currentQuest = 1;
        remove_item(2, 1);
    }
}

void quest1()
{
    if (quests[1].progress == 0)
    {
        show_notification(8);
        if (!show)
        {
            add_quest_progress(quests, 1, 10);
        }
    }
    if (quests[1].progress == 10)
    {
        if (calculateDistance(walle.x, walle.y, 600, 280) <= 30)
        {
            render_texture(renderer, uiItems[4].texture, 640 - camera_x, 250 - camera_y - 50, 40, 40);
            if (F)
            {
                add_quest_progress(quests, 1, 15);
                gameObjects[0].texture = load_texture("cofreabierto.png", renderer);
                add_item(1, 1);
            }

        }
    }

    if (quests[1].progress == 25)
    {
        show_notification(10);
            if (!show)
            {
                add_quest_progress(quests, 1, 25);
            }
    }
    if (quests[1].progress == 50)
    {
        if (enemies[0].health <= 0)
        {
            add_quest_progress(quests, 1, 25);
        }
    }
    if (quests[1].progress == 75)
    {
        show_notification(14);
        if (!show)
        {
            add_quest_progress(quests, 1, 10);
            levelInfo[15].IsClosed = FALSE;
        }
    }
    if (currentLevel == 3)
    {
        walle.currentQuest = 2;
    }
}


void quest2()
{
    if (quests[2].progress == 0)
    {
        show_notification(8);
        if (!show)
        {
            add_quest_progress(quests, 2, 10);
        }
    }
    if (quests[2].progress == 10)
    {
        int i = 72;
        int barruan = FALSE;
        while (i <= 76 && !barruan) {
            //printf("%d, %d\n", gameObjects[i].x, gameObjects[i].y);
             if (calculateDistance(walle.x, walle.y, gameObjects[i].x + gameObjects[i].objectWidth/2, gameObjects[i].y + gameObjects[i].objectHeight / 3) <= 120)
            {
                barruan = TRUE;
            }
            i++;
        }
        i -= 1;
        if (barruan) {
            render_texture(renderer, uiItems[4].texture, gameObjects[i].x - camera_x + 50, gameObjects[i].y - camera_y - 50, 40, 40);
            if (F) {
                if (has_item(3)) {

                }
                   }
        }
        

    }
    if (quests[2].progress == 25)
    {
        show_notification(10);
        if (!show)
        {
            add_quest_progress(quests, 1, 25);
        }
    }
    if (quests[2].progress == 50)
    {
        if (enemies[0].health <= 0)
        {
            add_quest_progress(quests, 1, 25);
        }
    }
    if (quests[1].progress == 75)
    {
        show_notification(14);
        if (!show)
        {
            add_quest_progress(quests, 1, 10);
            levelInfo[15].IsClosed = FALSE;
        }
    }
    if (currentLevel == 3)
    {
        walle.currentQuest = 2;
    }
}