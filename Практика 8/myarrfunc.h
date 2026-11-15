#ifndef MYARRFUNC_H
#define MYARRFUNC_H

void ochistit_bufer(void);
int zadat_razmer(int *n);

void zapolnit(int *arrptr, int n);
void pokazat(const int *arrptr, int n);
void dialog_summa_diapazona(const int *arrptr, int n);
void dialog_indeksy_diapazona(const int *arrptr, int n);
void dialog_indeksy_vyshe_srednego(const int *arrptr, int n);

#endif