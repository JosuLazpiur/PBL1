#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "objects.h"
#include "constants.h"
#include "update.h"

ObjectInfo gameObjects1[] = {

    //Habitacion 1
    {"cama", "cama2.png", TRUE, NULL, 325, 200, 125, 180, FALSE, FALSE},
    {"cama", "cama2.png", TRUE, NULL, 525, 200, 125, 180, FALSE, FALSE},
    {"cama", "cama2.png", TRUE, NULL, 725, 200, 125, 180, FALSE, FALSE},
    {"mesilla", "mesilla1.png", TRUE, NULL, 450, 200, 75, 100, FALSE, FALSE},
    {"mesilla", "mesilla1.png", TRUE, NULL, 650, 200, 75, 100, FALSE, FALSE},

    //PASILLO
    {"estanteria", "estanteria.png", TRUE, NULL, 2575, 150, 150, 150, FALSE, FALSE},
    {"estanteria", "estanteria.png", TRUE, NULL, 2925, 150, 150, 150, FALSE, FALSE},
    {"mesa", "mesa.png", TRUE, NULL, 2725, 206, 200, 75, FALSE, FALSE},
    {"mesilla", "mesilla.png", TRUE, NULL, 3025, 490, 75, 100, FALSE, FALSE},
    {"sofa", "sofa1.png", TRUE, NULL, 3000, 600, 125 ,250,FALSE,FALSE},

    //BAÑO1
    {"bañera", "banera.png", TRUE, NULL, 3725, 3300, 200, 150, FALSE, FALSE},
    {"lavamanos", "lavamanos.png", TRUE, NULL, 3980, 3300, 75, 75, FALSE, FALSE},
    {"retrete", "retrete.png", TRUE, NULL, 3720, 3600, 75, 100, FALSE, FALSE},
    //BAÑO2
    {"bañera", "banera.png", TRUE, NULL, 4325, 2240, 200, 150, FALSE, FALSE},
    {"lavamanos", "lavamanos.png", TRUE, NULL, 4580, 2230, 75, 75, FALSE, FALSE},
    {"retrete", "retrete.png", TRUE, NULL, 4315, 2528, 75, 100, FALSE, FALSE},

    //HABITACION 2 
    {"encimera", "encimera.png", TRUE, NULL, 4500, 560, 200, 100, FALSE, FALSE },
    {"encimera2", "encimera2.png", TRUE, NULL, 4700, 575, 100, 125, FALSE, FALSE },
    {"fogones", "fogones.png", TRUE, NULL, 4410, 560, 100, 100, FALSE, FALSE},
    {"mesa3", "mesa3.png", TRUE, NULL, 4600, 925, 150, 300, FALSE, FALSE},
    {"mesa3", "mesa3.png", TRUE, NULL, 4295, 925, 150, 300, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4555, 970, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4555, 1055, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4448, 970, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4448, 1055, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4230, 970, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4230, 1055, 50, 50, FALSE, FALSE},
    {"nevera", "nevera.png", TRUE, NULL, 4310, 490, 100, 200, FALSE, FALSE},

    //HABITACION 3
    {"generador", "generador.png", TRUE, NULL, 230, 1440, 250, 250, FALSE, FALSE},
    {"decoracion", "decoracionrota3.png", TRUE, NULL, 275, 1900, 250, 250, FALSE, FALSE},
    {"decoracion", "decoracionrota.png", TRUE, NULL, 880, 1550, 75, 75, FALSE, FALSE},
    {"decoracion", "decoracionrota.png", TRUE, NULL, 750, 1480, 125, 125, FALSE, FALSE},
    {"decoracion", "decoracionrota4.png", TRUE, NULL, 475, 1500, 125, 125, FALSE, FALSE},
    {"decoracion", "mesa1.png", TRUE, NULL, 770, 1775, 175, 125, FALSE, FALSE},

    //HABITACION SALIDA
    {"camara", "camara.png", FALSE, NULL, 385, 2910, 75, 75, FALSE, FALSE},
    {"camara", "camara2.png", FALSE, NULL, 1360, 2910, 75, 75, FALSE, FALSE},
    {"estanteria", "estanteria.png", TRUE, NULL, 655, 2900, 150, 150, FALSE, FALSE},
    {"estanteria", "estanteria.png", TRUE, NULL, 1000, 2900, 150, 150, FALSE, FALSE},
    {"reloj", "reloj.png", TRUE, NULL, 865, 2895, 75, 150, FALSE, FALSE},
    {"lampara", "lampara.png", TRUE, NULL, 795, 2950, 75, 100, FALSE, FALSE },
    {"perchero", "decoracion.png", TRUE, NULL, 945, 2920, 50, 125, FALSE, FALSE },
    {"sofa", "sofa3.png", TRUE, NULL, 405, 3200, 250, 150, FALSE, FALSE},
    {"sofa", "sofa3.png", TRUE, NULL, 1150, 3200, 250, 150, FALSE, FALSE},
    {"salida", "puertabunker.png", TRUE, NULL, 725, 3350, 350, 250, TRUE, 35},

    //PUERTAS
     {"puerta", "puerta.png", TRUE, NULL, 715, 695, 125, 150, TRUE, 35},
     {"puerta", "puerta.png", TRUE, NULL, 600, 1300, 125, 150, FALSE, FALSE},
     {"puerta", "puerta.png", TRUE, NULL, 715, 2135, 125, 150, TRUE, 35},
     {"puerta", "puerta.png", TRUE, NULL, 1198, 2750, 125, 150, FALSE, FALSE},
     {"puerta", "puerta.png", TRUE, NULL, 477, 2750, 125, 150, FALSE, FALSE},
     {"puerta", "puerta.png", TRUE, NULL, 2880, 1650, 125, 150, TRUE, 35},
     {"puerta", "puerta2.png", TRUE, NULL, 1075, 275, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 2390, 275, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 2620, 875, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 2620, 1352, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 4070, 755, 25, 200, FALSE, FALSE},
     {"puerta", "puerta2.png", TRUE, NULL, 3225, 1115, 25, 200, FALSE, FALSE},
     {"puerta", "puerta2.png", TRUE, NULL, 4794, 2315, 25, 200, FALSE, FALSE},
     {"puerta", "puerta2.png", TRUE, NULL, 4195, 3395, 25, 200, FALSE, FALSE},

    {NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0}
};

ObjectInfo gameObjects2[] = {
    {"ChestClosed", "cofrecerrado.png", TRUE, NULL, 600, 200, 80, 80, TRUE, 20},
    {"Bunker", "bunker.png", TRUE, NULL, 30, 200, 550, 400, FALSE, NULL},
    {"tronco", "tronco.png", TRUE, NULL, 900, 270, 80, 60},
    {"señal", "senal.png", TRUE, NULL, 1650, 260, 80, 100},

    {NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0}
};

ObjectInfo gameObjects3[] = {
    {"fuente", "fuente.png", TRUE, NULL, 900, 600, 250, 250, TRUE, 10},
    {"casa", "casa.png", TRUE, NULL, 380, 1260, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 625, 1740, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2300, 2340, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2675, 2340, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2300, 2815, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2660, 2815, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2180, 420, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2540, 420, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2900, 420, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 3260, 420, 300, 300, TRUE, 20},

    {"basura", "basura.png", TRUE, NULL, 995, 415, 50, 75, FALSE, FALSE},
    {"basura", "basura.png", TRUE, NULL, 825, 2800, 50, 75, FALSE, FALSE},
    {"basura", "basura.png", TRUE, NULL, 3315, 1495, 50, 75, FALSE, FALSE},

    {"banco", "banco.png", TRUE, NULL, 865, 415, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1400, 655, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1070, 415, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 475, 2800, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 650, 2800, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 925, 2800, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1100, 2800, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1100, 2800, 100, 75, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 3420, 1495, 100, 75, FALSE, FALSE},

    {"farola", "farola.png", TRUE, NULL, 375, 2585, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 825, 2585, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1275, 2585, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 900, 1325, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 775, 375, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1225, 375, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 375, 1815, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1100, 1805, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 185, 285, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1225, 800, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 775, 800, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2075, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2490, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2845, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 3210, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2535, 925, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 3250, 1315, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 3125, 2030, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2955, 3050, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2955, 3050, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2280, 3050, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2535, 1445, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2535, 925, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2280, 1970, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1270, 1945, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 360, 660, 50, 225, TRUE, 60},

    {"arbol", "arbol.png", TRUE, NULL, 540, 2390, 250, 300, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 1065, 2475, 150, 200, TRUE, 35},

    {"piedra", "piedras.png", TRUE, NULL, 850, 2525, 150, 100, FALSE, FALSE},

    // eje x
    {"vayas", "vayax.png", TRUE, NULL, 350, 2110, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 475, 2110, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 600, 2110, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 725, 2110, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 850, 2110, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 975, 2110, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 1100, 2110, 125, 75, TRUE, 1},

    {"vayas", "vayax.png", TRUE, NULL, 350, 1625, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 475, 1625, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 600, 1625, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 725, 1625, 125, 75, TRUE, 1},
    {"vayas", "vayax.png", TRUE, NULL, 850, 1625, 125, 75, TRUE, 1},


    //eje y
    {"vayas", "vayay.png", TRUE, NULL, 350, 2150, 25, 150, FALSE, FALSE},
    {"vayas", "vayay.png", TRUE, NULL, 350, 2275, 25, 150, FALSE, FALSE},
    {"vayas", "vayay.png", TRUE, NULL, 350, 2400, 25, 150, FALSE, FALSE},
    {"vayas", "vayay.png", TRUE, NULL, 350, 2525, 25, 150, FALSE, FALSE},
    {"vayas", "vayay.png", TRUE, NULL, 350, 2650, 25, 150, FALSE, FALSE},

    {"vayas", "vayay.png", TRUE, NULL, 350, 1665, 25, 150, FALSE, FALSE},
    {"vayas", "vayay.png", TRUE, NULL, 350, 1790, 25, 150, FALSE, FALSE},
    {"vayas", "vayay.png", TRUE, NULL, 350, 1915, 25, 150, FALSE, FALSE},

    // mision
     {"contendor", "contenedorverde.png", TRUE, NULL, 2800, 1050, 100, 100, FALSE, FALSE},
     {"contendor", "contenedormarron.png", TRUE, NULL, 3000, 1050, 100, 100, FALSE, FALSE},
     {"contendor", "contenerdoramarillo.png", TRUE, NULL, 2600, 1050, 100, 100, FALSE, FALSE},

     {"contendor", "contenedorazul.png", TRUE, NULL, 2600, 1450, 100, 100, FALSE, FALSE},
     {"contendor", "contenedorgris.png", TRUE, NULL, 2800, 1450, 100, 100, FALSE, FALSE},

     //basura

    {NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0}
};

ObjectInfo* gameObjects = gameObjects1;

void render_objects(SDL_Renderer* renderer)
{
    int i = 0;
    while (gameObjects[i].name != NULL)
    {
        // Calculate the object coordinates relative to the camera
        int objectX = gameObjects[i].x - round(camera_x);
        int objectY = gameObjects[i].y - round(camera_y);

        // Check if the object is within the screen
        if (objectX + gameObjects[i].objectWidth > 0 && objectX < windowWidth &&
            objectY + gameObjects[i].objectHeight > 0 && objectY < windowHeight)
        {

            int transparency = 255;
            if (gameObjects[i].isBehindUser)
            {
                transparency = 128;
            }
            SDL_SetTextureAlphaMod(gameObjects[i].texture, transparency);

            SDL_Rect objectRect;

            objectRect.x = objectX;
            objectRect.y = objectY;
            objectRect.w = gameObjects[i].objectWidth;
            objectRect.h = gameObjects[i].objectHeight;

            SDL_RenderCopy(renderer, gameObjects[i].texture, NULL, &objectRect);
        }
        i++;
    }
}
