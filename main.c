#include <stdio.h>
#include "system.h"
#include "quest.h"

int main() {
    setRussianLanguage(); // Установка русского языка в консоли
    setBackgorundColor(); // Установка цвета текста в консоли

    printf("------------------------------------------------ ЖУРНАЛ ТРЕНИРОВОК ------------------------------------------------");
    int choice;
    do {

        quest(); // Переход к выбору функционала программы
        printf("\nЖелаете продолжить? (1: Да, 0: Нет): ");
        scanf("%d", &choice);
        ClearConsole();

    } while (choice != 0); // Перезапуск программы
    return 0;
}