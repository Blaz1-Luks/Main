#ifndef MYMATFUNC_H
#define MYMATFUNC_H
#include <stddef.h>

void ochistit_bufer(void);
int zadat_razmer(int *rows, int *cols);
void zapolnit(int *matptr, int rows, int cols);
void pokazat(const int *matptr, int rows, int cols);

void summa_stolbtsov(const int *matptr, size_t rows, size_t cols, long *buf);
size_t kolvo_nizhe(const int *matptr, size_t rows, size_t cols, int k);
long summa_stolbtsov_diapazon(const int *matptr, size_t rows, size_t cols,
                              size_t k, size_t m);

void dialog_summa_stolbtsov(const int *matptr, int rows, int cols);
void dialog_kolvo_nizhe(const int *matptr, int rows, int cols);
void dialog_summa_stolbtsov_diapazon(const int *matptr, int rows, int cols);

#endif