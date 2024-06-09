#include "quest.h"
#include <stdio.h>
#include "hooks.h"

enum {START ,ADD, CHECKTRAN, CHECKSTOP ,REMOVE, ADVICE};

void quest(){

    int questionDataBool; // Переменная, имитирующая логику выбора
    printf("\nВыберите нужный функционал:\n");
    printf("\n1: Добавить транспорт\n2: Найти расписание транспорта \n3: Найти расписание остановки\n4: Удалить транспорт\n");
    scanf("%d", &questionDataBool); // Считывание переменной, имитирующей логику выбора
    switch (questionDataBool) {
        case ADD:
            createTransport(); // Функция добавления транспорта
            break;
        case CHECKTRAN:
            findTransport(); // Функция поиска траноспорта
            break;
        case CHECKSTOP:
            findStop();
            break;
        case REMOVE:
            removeTransport(); //Функция удаления транспорта
            break;
        default:
            printf("Неверный ввод"); // Обработка некорректного ввода
            break;
    }
}
