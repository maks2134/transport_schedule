#include "findstop.h"

// Создание структуры Schedule
struct Schedule* createSchedules(const char* number) {
    struct Schedule* schedule = (struct Schedule*)malloc(sizeof(struct Schedule));
    schedule->number = strdup(number);
    schedule->stops = NULL;
    schedule->times = NULL;
    schedule->stopCount = 0;
    schedule->left = schedule->right = NULL;
    return schedule;
}

// Вставка новой структуры Schedule в дерево
struct Schedule* inserts(struct Schedule* root, struct Schedule* newSchedule) {
    if (root == NULL)
        return newSchedule;

    if (strcmp(newSchedule->number, root->number) < 0)
        root->left = inserts(root->left, newSchedule);
    else if (strcmp(newSchedule->number, root->number) > 0)
        root->right = inserts(root->right, newSchedule);

    return root;
}

// Освобождение памяти дерева
void freeTrees(struct Schedule* root) {
    if (root == NULL)
        return;

    for (int i = 0; i < root->stopCount; i++) {
        free(root->stops[i]);
        free(root->times[i]);
    }
    free(root->stops);
    free(root->times);
    free(root->number);

    freeTrees(root->left);
    freeTrees(root->right);
    free(root);
}

// Загрузка расписаний из файла
void loadScheduless(struct Schedule** root, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char number[10];
        if (sscanf(line, "%s", number) == 1) {
            struct Schedule* schedule = createSchedules(number);

            while (fgets(line, sizeof(line), file) && strlen(line) > 1) {
                char stop[25], time[6];
                sscanf(line, "%s %s", stop, time);

                schedule->stops = realloc(schedule->stops, (schedule->stopCount + 1) * sizeof(char *));
                schedule->times = realloc(schedule->times, (schedule->stopCount + 1) * sizeof(char *));

                schedule->stops[schedule->stopCount] = strdup(stop);
                schedule->times[schedule->stopCount] = strdup(time);
                schedule->stopCount++;
            }
            *root = inserts(*root, schedule);
        }
    }
    fclose(file);
}

// Поиск остановок
void findStops(struct Schedule* root, const char* stop, int* found) {
    if (root == NULL)
        return;

    for (int i = 0; i < root->stopCount; i++) {
        if (strcmp(root->stops[i], stop) == 0) {
            printf("Транспорт: %s, Время прибытия: %s\n", root->number, root->times[i]);
            *found = 1;
        }
    }

    findStops(root->left, stop, found);
    findStops(root->right, stop, found);
}

// Основная функция поиска
void finding() {
    struct Schedule* root = NULL;
    loadScheduless(&root, "C:\\Users\\maks2\\CLionProjects\\transport_schedule\\schedule.txt");

    char stop[25];
    printf("Введите название остановки: ");
    scanf("%s", stop);

    int found = 0;
    findStops(root, stop, &found);

    if (!found) {
        printf("Транспорт, проходящий через эту остановку, не найден.\n");
    }

    freeTrees(root);
}