/* 
    Как программа отражает принципы архитектуры фон Неймана:
   1) единая память — команды и данные хранятся в одном массиве memory[256];
   2) программное управление — процессор сам выполняет команды одну за другой
      по счётчику команд cpu_state[0], программа загружена в ту же память;
   3) однородность памяти — любая ячейка может быть и командой, и данными
      (адрес из ячейки читается и как операнд, и как адрес перехода);
   4) состояние процессора хранится отдельно, в регистрах cpu_state:
      pc, acc, ir, вектор прерываний, флаг стопа, код ошибки. */
#include <stdio.h>

int main(void)
{
    int memory[256] = { 0 };  /* единая память: команды и данные */
    int cpu_state[8] = { 0 }; /* [0] pc, [1] acc, [2] ir, [3] вектор,
                                 [4] флаг стопа, [5] код ошибки */
    int komanda;  /* текущий опкод */
    int operand;  /* адрес ячейки или адрес перехода */
    int i;

    /* загрузка программы в память: каждое число ввода — одна ячейка */
    for (i = 0; i < 256 && scanf("%d", &memory[i]) == 1; i++)
        ;

    cpu_state[0] = 4;         /* первая команда (после данных) */
    cpu_state[3] = memory[0]; /* вектор прерываний из ячейки 0 */

    /* главный цикл: чтение команды -> декодирование -> исполнение */
    while (cpu_state[4] == 0) {
        if (cpu_state[0] < 0 || cpu_state[0] > 255) { /* pc вне памяти */
            printf("ОШИБКА: счётчик команд вне памяти\n");
            break;
        }

        /* чтение: опкод из ячейки pc кладём в регистр команд ir */
        komanda = cpu_state[2] = memory[cpu_state[0]];
        operand = 0; /* у команд 0 и 3 операнда нет */

        /* декодирование: команды 1, 2, 4 занимают две ячейки (код + операнд) */
        if (komanda == 1 || komanda == 2 || komanda == 4) {
            if (cpu_state[0] > 254) { /* операнд за границей памяти */
                printf("ОШИБКА: операнд вне памяти\n");
                cpu_state[0] = cpu_state[3]; /* прерывание по вектору */
                continue;
            }
            operand = memory[cpu_state[0] + 1]; /* операнд — следующая ячейка */
            if (operand < 0 || operand > 255) { /* адрес вне памяти */
                printf("pc=%d: команда %d, operand=%d, ОШИБКА: адрес вне памяти\n",
                       cpu_state[0], komanda, operand);
                cpu_state[5] = 1;
                cpu_state[0] = cpu_state[3]; /* прерывание по вектору */
                continue;
            }
        }

        /* исполнение */
        if (komanda == 0) { /* стоп */
            printf("pc=%d: команда 0, стоп\n", cpu_state[0]);
            cpu_state[4] = 1;
        }
        else if (komanda == 1) { /* загрузить в acc число из ячейки */
            cpu_state[1] = memory[operand];
            printf("pc=%d: команда 1, operand=%d, acc=%d\n",
                   cpu_state[0], operand, cpu_state[1]);
            cpu_state[0] = cpu_state[0] + 2;
        }
        else if (komanda == 2) { /* прибавить к acc число из ячейки */
            cpu_state[1] = cpu_state[1] + memory[operand];
            printf("pc=%d: команда 2, operand=%d, acc=%d\n",
                   cpu_state[0], operand, cpu_state[1]);
            cpu_state[0] = cpu_state[0] + 2;
        }
        else if (komanda == 3) { /* вывести acc, операнда нет */
            printf("pc=%d: команда 3, operand нет, acc=%d\n",
                   cpu_state[0], cpu_state[1]);
            cpu_state[0] = cpu_state[0] + 1;
        }
        else if (komanda == 4) { /* JUMP: pc = адрес перехода, а не pc += 2 */
            printf("pc=%d: команда 4, operand=%d, переход на %d\n",
                   cpu_state[0], operand, operand);
            cpu_state[0] = operand;
        }
        else { /* неизвестная команда — прерывание */
            printf("pc=%d: команда %d, ОШИБКА: неизвестная команда\n",
                   cpu_state[0], komanda);
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
        }
    }

    if (cpu_state[5] != 0) { /* итог: с ошибкой или нормально */
        printf("Программа завершена с ошибкой\n");
    } else {
        printf("Программа завершена\n");
    }
    return 0;
}
