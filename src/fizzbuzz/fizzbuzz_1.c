// fizzbuzz_1.c

// Naive solution


#include <stdio.h>
int main(){
    int N=30;
    int i;

    printf("\n\n--------------\n\n");
    for (i=1; i<=N; i++){
        if (i%3==0 && i%5==0 )
            printf("fizzbuzz\n");
        else if (i%3==0)
            printf("fizz\n");
        else if (i%5==0)
            printf("buzz\n");
        else
            printf("%d\n",i);
    }
}
