// quests.h
#ifndef QUESTS_H
#define QUESTS_H

#include <SDL.h>
#include "initializer.h" // Incluye los encabezados necesarios

typedef struct Quests_S {
    char* questName;
    int questLevel;
    int progress;
} Quests;

extern Quests quests[];

extern void add_quest_progress(Quests quests[], int currentQuest, int progressQuantity);
extern void quest_manager(Quests quests[]);
extern void render_mission_text(Quests quests[], int currentMissionIndex);
extern void renderMissionProgress(Quests quests[]);
void quest0();
void quest1();
void quest2();

#endif // QUESTS_H
