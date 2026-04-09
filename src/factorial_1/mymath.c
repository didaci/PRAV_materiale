
#include <stdio.h>
#include "mymath.h"

float pi=3.14; //exported in mymath.h

int myfactorial(int n){
    int nMax=7;
    int f,i;
    if (n> nMax){
        printf("Too big!");
        return -1;
    }
    if (n==0) return 1;
    else {
        f=1;
        for (i=2; i<=n; i++)
            f=f*i;
        return f;
    }
}
