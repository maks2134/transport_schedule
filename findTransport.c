#include "findTransport.h"

struct Schedule* createSchedule(const char* number) {
    struct Schedule* schedule = (struct Schedule*)malloc(sizeof(struct Schedule));
    schedule->number = strdup(number);
    schedule->stops = NULL;
    schedule->times = NULL;
    schedule->stopCount = 0;
    schedule->left = schedule->right = NULL;
    return schedule;
}

struct Schedule* insert(struct Schedule* root, struct Schedule* newSchedule) {
    if (root == NULL)
        return newSchedule;

    if (strcmp(newSchedule->number, root->number) < 0)
        root->left = insert(root->left, newSchedule);
    else if (strcmp(newSchedule->number, root->number) > 0)
        root->right = insert(root->right, newSchedule);

    return root;
}

struct Schedule* search(struct Schedule* root, const char* number) {
    if (root == NULL || strcmp(root->number, number) == 0)
        return root;

    if (strcmp(number, root->number) < 0)
        return search(root->left, number);
    else
        return search(root->right, number);
}

void printSchedule(struct Schedule* schedule) {
    if (schedule == NULL) {
        printf("Транспорт с таким номером не найден.\n");
        return;
    }

    printf("%s \n", schedule->number);
    for (int i = 0; i < schedule->stopCount; i++) {
        printf("%s %s\n", schedule->stops[i], schedule->times[i]);
    }
}

void freeTree(struct Schedule* root) {
    if (root == NULL)
        return;

    for (int i = 0; i < root->stopCount; i++) {
        free(root->stops[i]);
        free(root->times[i]);
    }
    free(root->stops);
    free(root->times);
    free(root->number);

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void loadSchedules(struct Schedule** root, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char number[10];
        if (sscanf(line, "%s", number) == 1) {
            struct Schedule* schedule = createSchedule(number);

            while (fgets(line, sizeof(line), file) && strlen(line) > 1) {
                char stop[25], time[6];
                sscanf(line, "%s %s", stop, time);

                schedule->stops = realloc(schedule->stops, (schedule->stopCount + 1) * sizeof(char *));
                schedule->times = realloc(schedule->times, (schedule->stopCount + 1) * sizeof(char *));

                schedule->stops[schedule->stopCount] = strdup(stop);
                schedule->times[schedule->stopCount] = strdup(time);
                schedule->stopCount++;
            }
            *root = insert(*root, schedule);
        }
    }
    fclose(file);
}

void find() {
    struct Schedule* root = NULL;
    loadSchedules(&root, "C:\\Users\\maks2\\CLionProjects\\transport_schedule\\schedule.txt");
    char number[10];
    printf("Введите номер интересующего вас транспорта (например, 4A): ");
    scanf("%s", number);
    struct Schedule* schedule = search(root, number);
    printSchedule(schedule);
    freeTree(root);
}