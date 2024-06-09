#ifndef TRANSPORT_SCHEDULE_FINDTRANSPORT_H
#define TRANSPORT_SCHEDULE_FINDTRANSPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

// Функции для работы с бинарным деревом поиска
struct Schedule* insert(struct Schedule* root, struct Schedule* newSchedule);
struct Schedule* search(struct Schedule* root, int number);
void printSchedule(struct Schedule* schedule);
void find();
void freeTree(struct Schedule* root);

#endif //TRANSPORT_SCHEDULE_FINDTRANSPORT_H