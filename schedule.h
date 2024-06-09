#ifndef TRANSPORT_SCHEDULE_SCHEDULE_H
#define TRANSPORT_SCHEDULE_SCHEDULE_H
struct Schedule {
    int number;
    char **stops;
    char **times;
    int stopCount;
    struct Schedule *left, *right;
};
#endif