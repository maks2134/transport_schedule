#include "createTransport.h"

void create() {
    struct Schedule schedule;
    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\transport_schedule\\schedule.txt", "a");

    if (file == NULL) {
        printf("Ошибка открытия файла для записи.\n");
        return;
    }

    schedule.stopCount = 0;
    schedule.stops = NULL;
    schedule.times = NULL;

    char number[10];
    printf("Введите номер транспорта (например, 4A): ");
    scanf("%s", number);
    schedule.number = strdup(number);

    int choice;
    do {
        char stop[25];
        char time[6];

        printf("Введите название остановки: ");
        scanf("%s", stop);

        printf("Введите время прибытия (чч.мм): ");
        scanf("%s", time);

        schedule.stops = realloc(schedule.stops, (schedule.stopCount + 1) * sizeof(char *));
        schedule.times = realloc(schedule.times, (schedule.stopCount + 1) * sizeof(char *));

        if (schedule.stops == NULL || schedule.times == NULL) {
            printf("Ошибка выделения памяти.\n");
            return;
        }

        schedule.stops[schedule.stopCount] = strdup(stop);
        schedule.times[schedule.stopCount] = strdup(time);
        schedule.stopCount++;

        printf("Хотите добавить ещё одну остановку?\n1-да\n2-нет: ");
        scanf("%d", &choice);

    } while (choice == 1);

    fprintf(file, "%s \n", schedule.number);
    for (int i = 0; i < schedule.stopCount; i++) {
        fprintf(file, "%s %s\n", schedule.stops[i], schedule.times[i]);
    }
    fprintf(file, "\n");

    fclose(file);

    for (int i = 0; i < schedule.stopCount; i++) {
        free(schedule.stops[i]);
        free(schedule.times[i]);
    }
    free(schedule.stops);
    free(schedule.times);
    free(schedule.number);

    printf("Информация успешно записана в файл.\n");
}