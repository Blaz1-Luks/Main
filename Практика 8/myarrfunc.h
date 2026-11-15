#ifndef MYARRFUNC_H
#define MYARRFUNC_H
#include <stddef.h>

void ochistit_bufer(void);
int zadat_razmer(int *n);
void zapolnit(int *arrptr, int n);
void pokazat(const int *arrptr, int n);

int summa_diapazona(const int *arrptr, size_t n, size_t k, size_t m);
int indeksy_v_diapazone(const int *arrptr, size_t n, int k, int m);
int indeksy_vyshe_srednego(const int *arrptr, size_t n);
void dialog_summa_diapazona(const int *arrptr, int n);
void dialog_indeksy_diapazone(const int *arrptr, int n);
void dialog_indeksy_vyshe_srednego(const int *arrptr, int n);

#endif