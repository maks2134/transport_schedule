#ifndef TRANSPORT_SCHEDULE_FINDTRANSPORT_H
#define TRANSPORT_SCHEDULE_FINDTRANSPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

struct Schedule* createSchedule(const char* number);
struct Schedule* insert(struct Schedule* root, struct Schedule* newSchedule);
struct Schedule* search(struct Schedule* root, const char* number);
void printSchedule(struct Schedule* schedule);
void freeTree(struct Schedule* root);
void loadSchedules(struct Schedule** root, const char* filename);
void find();

#endif //TRANSPORT_SCHEDULE_FINDTRANSPORT_H