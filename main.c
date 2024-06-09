#include <stdio.h>
#include "system.h"
#include "quest.h"
#include "windows.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    printf("------------------------------------------------ РАСПИСАНИЕ ТРАНСПОРТА ------------------------------------------------\n");
    int choice;
    do {
        quest(); // Переход к выбору функционала программы

        // Проверка корректности ввода для продолжения программы
        while (1) {
            printf("\nЖелаете продолжить? (1: Да, 0: Нет): ");
            if (scanf("%d", &choice) == 1 && (choice == 0 || choice == 1)) {
                break;
            } else {
                printf("Неверный ввод. Пожалуйста, введите 1 для продолжения или 0 для выхода.\n");
                while (getchar() != '\n'); // Очистка буфера ввода
            }
        }
        ClearConsole();
    } while (choice != 0); // Перезапуск программы
    return 0;
}