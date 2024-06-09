#include "removeTransport.h"

void delete() {
    int number;
    printf("Введите номер интересующего вас транспорта: ");
    scanf("%d", &number);

    FILE *file = fopen("C:\\Users\\maks2\\CLionProjects\\transport_schedule\\schedule.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения.\n");
        return;
    }

    FILE *temp = fopen("C:\\Users\\maks2\\CLionProjects\\transport_schedule\\temp.txt", "w");
    if (temp == NULL) {
        printf("Ошибка открытия временного файла для записи.\n");
        fclose(file);
        return;
    }

    char line[256];
    int currentNumber = -1;
    int skip = 0;

    while (fgets(line, sizeof(line), file)) {
        // Check if the line contains a bus number
        if (sscanf(line, "%d bus", &currentNumber) == 1) {
            // Set the skip flag if the current bus number matches the number to be removed
            skip = (currentNumber == number);
        }

        // Write the line to the temp file only if we're not skipping
        if (!skip) {
            fputs(line, temp);
        } else if (strlen(line) == 1) { // Check for an empty line indicating end of a bus block
            skip = 0; // Reset the skip flag after the bus block has been skipped
        }
    }

    fclose(file);
    fclose(temp);

    if (remove("C:\\Users\\maks2\\CLionProjects\\transport_schedule\\schedule.txt") != 0) {
        printf("Ошибка удаления оригинального файла.\n");
        return;
    }
    if (rename("C:\\Users\\maks2\\CLionProjects\\transport_schedule\\temp.txt", "C:\\Users\\maks2\\CLionProjects\\transport_schedule\\schedule.txt") != 0) {
        printf("Ошибка переименования временного файла.\n");
        return;
    }

    printf("Информация о транспорте с номером %d успешно удалена.\n", number);
}