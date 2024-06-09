#include "quest.h"
#include <stdio.h>
#include "hooks.h"

enum {START, ADD = 1, CHECKTRAN, CHECKSTOP, REMOVE, ADVICE};

void quest() {
    int questionDataBool; // Переменная, имитирующая логику выбора

    printf("\nВыберите нужный функционал:\n");
    printf("1: Добавить транспорт\n2: Найти расписание транспорта\n3: Найти расписание остановки\n4: Удалить транспорт\n");

    // Проверка корректности ввода для выбора функционала
    while (1) {
        if (scanf("%d", &questionDataBool) == 1 && questionDataBool >= ADD && questionDataBool <= REMOVE) {
            break;
        } else {
            printf("Неверный ввод. Пожалуйста, выберите номер от 1 до 4.\n");
            while (getchar() != '\n'); // Очистка буфера ввода
        }
    }

    switch (questionDataBool) {
        case ADD:
            createTransport(); // Функция добавления транспорта
            break;
        case CHECKTRAN:
            findTransport(); // Функция поиска транспорта
            break;
        case CHECKSTOP:
            findStop();
            break;
        case REMOVE:
            removeTransport(); // Функция удаления транспорта
            break;
        default:
            printf("Неверный ввод"); // Обработка некорректного ввода (на всякий случай)
            break;
    }
}