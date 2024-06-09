#ifndef TRANSPORT_SCHEDULE_SCHEDULE_H
#define TRANSPORT_SCHEDULE_SCHEDULE_H

struct Schedule {
    char *number;
    char **stops;
    char **times;
    int stopCount;
    struct Schedule *left;
    struct Schedule *right;
};

#endif //TRANSPORT_SCHEDULE_SCHEDULE_H