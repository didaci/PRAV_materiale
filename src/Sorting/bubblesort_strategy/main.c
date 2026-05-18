#include <stdio.h>
#include <stdbool.h>



void bubbleSort(int* v, int n, int (* criterio ) (int v1, int v2)){
    int tmp,j=0, p=n;
    bool continua;
    do {
        continua=false;
        for (int i=0; i<n-1; i++){
            //if (v[i]>v[i+1]){ // SWAP
            if (criterio(v[i],v[i+1])) {// SWAP
                continua=true;
                p=i+1;
                tmp=v[i]; v[i]=v[i+1]; v[i+1]=tmp;
            } // end IF
        } // end FOR
        n=p;
    }
    while (continua && n>1); // con n==2 -> i==0;  non è necessario arrivare a n==1
}
void printArray(int* v, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("]\n");
}

// ------------

// chi scrive il main è responsabile del codice seguente

// funzioni per definire il criterio di ordinamento 

int gt (int a, int b){return a>b;}; //greater than
int lt (int a, int b){return a<b;}; // less than

// se dovessi ordinare un array di strutture...
struct s {  int v1; int v2; int v3; int v4; };
int compare_v1 (struct s a, struct s b){ return a.v1> b.v1;}



int main() {


    int vett[6]={9,18,7,15,21,11};
    int nEl=6;
    int (* p ) (int v1, int v2); // puntatore a funzione 
    printArray(vett, nEl);
    p=gt; //greater than
    bubbleSort( vett, nEl, p);
    printArray(vett, nEl);
    p=lt; // less than
    bubbleSort( vett, nEl, p);
    printArray(vett, nEl);

    return 0;
}
