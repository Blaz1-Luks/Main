#include <stdio.h>

int main(void) 
{   
    int n=8;
    double a[n];
    double sum=0.0;
    double cur=1.0;
    double nxt=1.0;

    for (int i=0; i<n; i++) {
        a[i]=cur;
        sum=sum+a[i];

        double tmp=cur+nxt;
        cur=nxt; 
        nxt=tmp;

        tmp=cur + nxt;
        cur=nxt;
        nxt=tmp;
    }

    for (int i=0; i<n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    double avg=sum/n;
    printf("%.2f\n", avg);

    return 0;
}