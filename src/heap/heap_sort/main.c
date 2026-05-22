#include <stdio.h>

# define MAX_EL 13

void printArray(int* v, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");
}
// HEAP - accesso ai nodi

int parent(int i){ return (i-1)/2; }
int left(int i){ return 2*i+1;}
int right(int i){ return 2*(i+1); }

void max_heapify(int* A, int i, int heap_size){
    int l, r, idx_max, max;
    l=left(i);
    r=right(i);

    if ( l<heap_size && A[l]>A[i] ){ // figlio SX esistente && SX è il massimo
        idx_max=l;
    }
    else{// figlio SX NON esistente OPPURE esiste ma non è  il massimo
        // - > il massimo tra sx e i  è i
        idx_max=i;
    }
    // stesso confronto tra il max attuale e figlio DX, se esiste


    // se r è valido,
    //  se A[r]>MASSIMO,  MASSIMO=A[r]. Altrimenti PASS;
    if ( r<heap_size && A[r]>A[idx_max] ){ // figlio DX esistente && DX è il massimo
        idx_max=r;
    }
    // SE figlio DX NON esistente OPPURE esiste ma non è  il massimo
    // - > il massimo è quello determinato precedentemente

    // -------------------

    // se il massimo  è A[i], non occorre fare nulla (è già un max_heap)

    // se il massimo NON è A[i],
    //  - scambia con il figlio con il valore massimo
    //  -  applica max_heapify al figlio scambiato
    if (A[idx_max]!=A[i]){
        max =  A[idx_max];
        A[idx_max]= A[i];
        A[i]=max;
        max_heapify(A, idx_max,  heap_size);
    }
}


void build_max_heap(int* A, int heap_size){
    for (int i=(heap_size-1)/2; i>=0; i--){
        max_heapify(A, i,  heap_size);

    }
}

void heapsort(int* A, int heap_size){
    int tmp;

    build_max_heap(A, heap_size);
    //printArray(A, heap_size);

    for (int i=heap_size; i>1; i--){
        // swap radice con ultimo elemento
        tmp=A[i-1];
        A[i-1]= A[0];
        A[0]=tmp;

        max_heapify(A, 0,  i-1);
    }
}



int main() {


    int vett[MAX_EL]={4,1,3,2,16,9,10, 14,8,7, -1, -1, -1};
    int heap_size=10;
    printf("vettore\n");
    printArray(vett, heap_size);

    build_max_heap(vett, heap_size);
    printf("max heap\n");
    printArray(vett, heap_size);
    printf("vettore ordinato\n");
    heapsort(vett, heap_size);

    printArray(vett, heap_size);
 
    getchar();
    return 0;
}
