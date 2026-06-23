// notification.h
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "initializer.h" // Incluye los encabezados necesarios

typedef struct messages_S {
    int num;
    char message[60];
    int till;
} messages;

extern messages GameMessages[];

extern SPACE;

extern currentMessageIndex;
extern show;

extern void show_notification(int num);

#endif // NOTIFICATION_H
