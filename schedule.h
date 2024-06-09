#ifndef TRANSPORT_SCHEDULE_SCHEDULE_H
#define TRANSPORT_SCHEDULE_SCHEDULE_H

// Структура Schedule описывает расписание для определенного транспортного средства.
struct Schedule {
    char *number;  // Номер транспортного средства (например, "4A").
    char **stops;  // Массив строк, хранящих названия остановок.
    char **times;  // Массив строк, хранящих время прибытия на соответствующие остановки.
    int stopCount; // Количество остановок, через которые проходит транспортное средство.
    struct Schedule *left;  // Указатель на левое поддерево в бинарном дереве расписаний.
    struct Schedule *right; // Указатель на правое поддерево в бинарном дереве расписаний.
};

#endif // TRANSPORT_SCHEDULE_SCHEDULE_H