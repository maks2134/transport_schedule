#include "findTransport.h"

struct Schedule* createSchedule(int number) {
    struct Schedule* schedule = (struct Schedule*)malloc(sizeof(struct Schedule));
    schedule->number = number;
    schedule->stops = NULL;
    schedule->times = NULL;
    schedule->stopCount = 0;
    schedule->left = schedule->right = NULL;
    return schedule;
}

struct Schedule* insert(struct Schedule* root, struct Schedule* newSchedule) {
    if (root == NULL)
        return newSchedule;

    if (newSchedule->number < root->number)
        root->left = insert(root->left, newSchedule);
    else if (newSchedule->number > root->number)
        root->right = insert(root->right, newSchedule);

    return root;
}

struct Schedule* search(struct Schedule* root, int number) {
    if (root == NULL || root->number == number)
        return root;

    if (number < root->number)
        return search(root->left, number);
    else
        return search(root->right, number);
}

void printSchedule(struct Schedule* schedule) {
    if (schedule == NULL) {
        printf("Транспорт с таким номером не найден.\n");
        return;
    }

    printf("%d bus\n", schedule->number);
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
        int number;
        if (sscanf(line, "%d bus", &number) == 1) {
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

    int number;
    printf("Введите номер интересующего вас транспорта: ");
    scanf("%d", &number);

    struct Schedule* schedule = search(root, number);
    printSchedule(schedule);

    freeTree(root);
}